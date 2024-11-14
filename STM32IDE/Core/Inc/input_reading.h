/*
 * input_reading.h
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

//--- Private Include ----------------------------

#include "main.h"
#include "lab3.h"
#include "timer.h"

//--- Functions Declaration ----------------------

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
//unsigned char is_button_pressed_1s(unsigned char index);

//--- Private Defines ----------------------------

#define DEBOUNCE_TIME			1000

#define BUTTON_STATUS_RELEASE 	GPIO_PIN_SET
#define BUTTON_STATUS_PRESSED 	GPIO_PIN_RESET




#endif /* INC_INPUT_READING_H_ */
