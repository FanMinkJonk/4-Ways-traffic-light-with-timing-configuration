/*
 * led_7_segment.h
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#ifndef INC_LED_7_SEGMENT_H_
#define INC_LED_7_SEGMENT_H_

//--- Private Include ----------------------------

#include "main.h"
#include "lab3.h"

//--- Variables ----------------------------------

//- Global Variables -----------------------------
extern const int MAX_LED;
extern int buffer_led[4];
extern uint8_t index_led;

//--- Functions Declaration ----------------------

void update7SEG(int index);
void toggle7SEG(uint8_t num);

#endif /* INC_LED_7_SEGMENT_H_ */
