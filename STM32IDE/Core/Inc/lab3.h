/*
 * lab3.h
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */

#ifndef INC_LAB3_H_
#define INC_LAB3_H_

//--- Private Include ----------------------------

#include "main.h"
#include "fsm_input_processing.h"
#include "fsm_traffic_mode.h"
#include "input_reading.h"

//--- Variables ----------------------------------

extern uint8_t flag_l;
extern uint8_t flag_m;
extern uint8_t flag_i;
extern uint8_t flag_s;

extern uint8_t flag_one_sec;
extern uint8_t flag_seg;
extern uint8_t flag_blinky_led;

//--- Functions Declaration ----------------------

void init_lab3(uint32_t Prescaler, uint32_t Period);
void run_lab3();

//--- Private Defines ----------------------------

//- Necessities ----------------------------------
#define N0_OF_BUTTONS 3

//- TRAFFIC MODES --------------------------------
#define MODE_AUTO			1
#define MODE_RED_CONFIG		2
#define MODE_AMBER_CONFIG	3
#define MODE_GREEN_CONFIG	4

//- TRAFFIC LIGHT AUTOMATIC MODE -----------------
#define STATUS_RED_GREEN	11
#define STATUS_RED_AMBER	12
#define STATUS_GREEN_RED	13
#define STATUS_AMBER_RED	14

//- TRAFFIC BUTTONS ------------------------------
#define BUTTON_MODE		0
#define BUTTON_INCREASE	1
#define BUTTON_SET		2







#endif /* INC_LAB3_H_ */
