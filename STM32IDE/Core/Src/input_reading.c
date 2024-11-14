/*
 * input_reading.c
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */
//--- Private Include ----------------------------

#include "input_reading.h"

//--- Variables ----------------------------------

//- Local Variables ------------------------------
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

static GPIO_PinState flagForButtonPress[N0_OF_BUTTONS] = {1, 1, 1};
static GPIO_PinState flagForButtonPress1s[N0_OF_BUTTONS];

//static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

//--- Functions Definition -----------------------

void button_reading(void){
	for(int i = BUTTON_MODE; i < N0_OF_BUTTONS; ++i){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, (BUTTON_MODE_Pin << i));
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			flagForButtonPress[i] = debounceButtonBuffer1[i];
//			if(flagForButtonPress[i] == BUTTON_STATUS_PRESSED){
//				if(counterForButtonPress1s[i] < (DEBOUNCE_TIME/TIMECYCLE)){
//					counterForButtonPress1s[i]++;
//				} else {
//					flagForButtonPress1s[i] = 1;
//					counterForButtonPress1s[i] = 0;
//				}
//			} else {
//				counterForButtonPress1s[i] = 0;
//				flagForButtonPress1s[i] = 0;
//			}
		}
	}
}

unsigned char is_button_pressed(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (flagForButtonPress[index] == BUTTON_STATUS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}
