/*
 * can.c
 *
 *  Created on: Dec 9, 2024
 *      Author: shaun
 */

#include "driverlib.h"
#include "device.h"

#include "Drivers/can.h"


/* lock/unlock critical sections */
#define CAN_LOCK() {DINT;}
#define CAN_UNLOCK() {EINT;}

#define CAN_BUF_RX_SIZE     32
#define CAN_BUF_TX_SIZE     32

can_t can_buf_rx[ CAN_BUF_RX_SIZE ];
can_t can_buf_tx[ CAN_BUF_TX_SIZE ];

uint16_t volatile can_buf_rx_head = 0;
uint16_t can_buf_rx_tail = 0;
uint16_t volatile can_buf_rx_cnt = 0;
uint16_t can_buf_tx_head = 0;
uint16_t volatile can_buf_tx_tail = 0;
uint16_t volatile can_buf_tx_cnt = 0;
uint16_t can_tx_is_active = 0;


void can_mbox_write(can_t *frame)
{
  uint32_t volatile tmp;

  /* this generates an interrupt every time */
  can_tx_is_active = 1;

  /* set as valid and transmit obj */
  CAN_setupMessageObject(CANA_BASE, 1, frame->id, CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE, frame->buf_len);
  CAN_sendMessage(CANA_BASE, 1, frame->buf_len, frame->buf);
}

void CANA_TX_ISR()
{
    // If there is nothing to transmit, then exit
    if(can_buf_tx_cnt) {
        // Decrement buffer count
        can_buf_tx_cnt--;
        // Load next message
        can_mbox_write(&can_buf_tx[can_buf_tx_tail]);
        // Increment FIFO tail pointer
        if( ++can_buf_tx_tail >= CAN_BUF_TX_SIZE )
            can_buf_tx_tail = 0;
    } else
    // The buffer is empty, transmission is no longer active
    can_tx_is_active = 0;

    // Clear interrupt flags
    CAN_clearInterruptStatus(CANA_BASE, 1);
    CAN_clearGlobalInterruptStatus(CANA_BASE, CAN_GLOBAL_INT_CANINT0);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

uint16_t can_tx(can_t *frame)
{
    uint16_t ret = 0;
    // Lock interrupts
    CAN_LOCK();
    // Check if CAN messages are already being sent
    if (can_tx_is_active)
    {
        // Check if there is room in the buffer
        if (can_buf_tx_cnt < CAN_BUF_TX_SIZE)
        {
            // Move CAN frame into the buffer
            can_buf_tx[ can_buf_tx_head ] = *frame;
            // Increment the FIFO head pointer
            if( ++can_buf_tx_head[p] >= CAN_BUF_TX_SIZE )
                     can_buf_tx_head[p] = 0;
            // Increment the buffer count
            can_buf_tx_cnt++;
        }
        else
            // Buffer is full, return 1
            ret = 1;
    }
    else
        // Write to the CAN mailbox directly if not already sending messages
        can_mbox_write(frame);
    // Unlock interrupts
    CAN_UNLOCK();
    // Return status
    return ret;
}

void CANA_RX_ISR()
{
    can_t *frame;
    can_t temp_frame;
    CAN_MsgFrameType frameType

    // Is there room in the buffer
    if( can_buf_rx_cnt < CAN_BUF_RX_SIZE ) {
        // Increment the buffer count
        can_buf_rx_cnt++;
        // Grab the next available pointer in the buffer
        frame = (can_t *)&can_buf_rx[can_buf_rx_head];
        // Increment the FIFO head pointer
        if( ++can_buf_rx_head[p] >= CAN_BUF_RX_SIZE )
            can_buf_rx_head[p] = 0;

    } else
        // Buffer is full, but a read operation still needs to occur
        frame = (can_t *)&tmp_frame;

    CAN_readMessageWithID(CANA_BASE, 2, &frameType, &(frame->id), &(frame->buf));
    frame->buf_len = 8;

    // Clear interrupt flags
    CAN_clearInterruptStatus(CANA_BASE, 2);
    CAN_clearGlobalInterruptStatus(CANA_BASE, CAN_GLOBAL_INT_CANINT1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

uint16_t can_rx(can_t *frame)
{
    uint16_t ret = 0;
    // Lock interrupts
    CAN_LOCK();
    // Check if there is anything in the buffer
    if( can_buf_rx_cnt[p] )
    {
        // Decrement the buffer count
        can_buf_rx_cnt--;
        // Copy the frame from the buffer
        *frame = can_buf_rx[can_buf_rx_tail];
        // Increment the FIFO tail pointer
        if( ++can_buf_rx_tail >= CAN_BUF_RX_SIZE )
            can_buf_rx_tail = 0;
    }
}

void CAN_Init()
{
    //
    // Configure the pin
    //
    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANTXA);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_CANTXA, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_CANTXA, GPIO_QUAL_ASYNC);

    GPIO_setPinConfig(DEVICE_GPIO_CFG_CANRXA);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_CANRXA, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_CANRXA, GPIO_QUAL_ASYNC);

    //
    // Configure the peripheral
    //
    CAN_initModule(CANA_BASE);
    // Set up the CAN bus bit rate to 500kHz for each module
    CAN_setBitRate(CANA_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);

    //
    // Enable CAN Interrupts
    //
    CAN_enableInterrupt(CANA_BASE, CAN_INT_ERROR | CAN_INT_IE0 | CAN_INT_IE1 | CAN_INT_STATUS);
    Interrupt_register(INT_CANA0, &CANA_TX_ISR);
    Interrupt_register(INT_CANA1, &CANA_RX_ISR);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
    CAN_enableGlobalInterrupt(CANA_BASE, CAN_GLOBAL_INT_CANINT0 | CAN_GLOBAL_INT_CANINT1);
    Interrupt_enable(INT_CANA0);
    Interrupt_enable(INT_CANA1);

    //
    // Configure message objects
    //
    CAN_setupMessageObject(CANA_BASE, 1, 0, CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE, 8);
    CAN_setupMessageObject(CANA_BASE, 2, 0, CAN_MSG_FRAME_STD, CAN_MSG_OBJ_TYPE_RX, 0, CAN_MSG_OBJ_RX_INT_ENABLE, 8);

    //
    // Start CAN module operations
    //
    CAN_startModule(CANA_BASE);
}
