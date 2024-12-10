/*
 * can.h
 *
 *  Created on: Dec 9, 2024
 *      Author: shaun
 */

#ifndef DRIVERS_CAN_H_
#define DRIVERS_CAN_H_

typedef struct
{
  uint32_t id;
  uint16_t  buf[8];
  uint16_t  buf_len;
} can_t;

extern void CAN_Init();
extern uint16_t can_tx(can_t *frame);
extern uint16_t can_rx(can_t *frame);

#endif /* DRIVERS_CAN_H_ */
