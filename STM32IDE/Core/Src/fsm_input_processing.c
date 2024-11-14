/*
 * fsm_input_processing.c
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "fsm_input_processing.h"

//--- Variables ----------------------------------

uint8_t buttonState[N0_OF_BUTTONS] = {BUTTON_STATE_RELEASE, BUTTON_STATE_RELEASE, BUTTON_STATE_RELEASE};

//--- Functions Definition -----------------------

void fsm_input_processing(){
	for(uint8_t i = BUTTON_MODE; i<N0_OF_BUTTONS; ++i){
		switch(buttonState[i]){
		case BUTTON_STATE_RELEASE:
			if(is_button_pressed(i)){
				buttonState[i] = BUTTON_STATE_PRESSED;
				flag_m = (i == BUTTON_MODE);
				flag_i = (i == BUTTON_INCREASE);
				flag_s = (i == BUTTON_SET);
			}
			break;
		case BUTTON_STATE_PRESSED:
			if(!is_button_pressed(i)){
				buttonState[i] = BUTTON_STATE_RELEASE;
				break;
			}
//			if(is_button_pressed_1s(i)){
//				buttonState[i] = BUTTON_STATE_PRESSED_1S;
//			}
			break;
//		case BUTTON_STATE_PRESSED_1S:
//			if(!is_button_pressed(i)){
//				buttonState[i] = BUTTON_STATE_RELEASE;
//			}
//			//TODO
//			if(is_button_pressed_1s(INPUT_MODE_ID)){
//				flag_m = 1;
//			}
//			break;
		default:
			break;
		}
	}
}
