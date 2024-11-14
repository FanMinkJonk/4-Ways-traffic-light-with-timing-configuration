/*
 * fsm_input_processing.h
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */

#ifndef INC_FSM_INPUT_PROCESSING_H_
#define INC_FSM_INPUT_PROCESSING_H_

//--- Private Include ----------------------------

#include "main.h"
#include "lab3.h"
#include "input_reading.h"

//--- Functions Declaration ----------------------

void fsm_input_processing(void);

//--- Private Defines ----------------------------

#define BUTTON_STATE_RELEASE	1
#define BUTTON_STATE_PRESSED	2
#define BUTTON_STATE_PRESSED_1S	3

#endif
