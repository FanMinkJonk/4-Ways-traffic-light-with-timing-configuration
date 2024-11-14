/*
 * fsm_traffic_mode.h
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#ifndef INC_FSM_TRAFFIC_MODE_H_
#define INC_FSM_TRAFFIC_MODE_H_

//--- Private Include ----------------------------

#include "main.h"
#include "lab3.h"
#include "timer.h"
#include "led_7_segment.h"

//--- Variables ----------------------------------

extern uint8_t status_traffic;
extern uint8_t status_light;

//--- Functions Declaration ----------------------

void init_fsm_traffic_mode(void);
void fsm_traffic_mode(void);

#endif /* INC_FSM_TRAFFIC_MODE_H_ */
