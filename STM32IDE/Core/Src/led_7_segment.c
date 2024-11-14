/*
 * led_7_segment.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "led_7_segment.h"

//--- Variables ----------------------------------

//- Global Variables -----------------------------
const int MAX_LED = 4;
int buffer_led[4] = {0,0,0,0};

//- Local Variables ------------------------------
uint8_t pattern_number[10] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x00, 0x04};
uint8_t index_led 		   = 0;

//--- Functions Definition -----------------------
//- Local Functions ------------------------------
void display7SEG1(int num){
	//---0---
	//-5   1-
	//---6---
	//-4   2-
	//---3---
	HAL_GPIO_WritePin(LED_7SEG1_1_GPIO_Port, LED_7SEG1_1_Pin, (0x40 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG1_2_GPIO_Port, LED_7SEG1_2_Pin, (0x20 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG1_3_GPIO_Port, LED_7SEG1_3_Pin, (0x10 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG1_4_GPIO_Port, LED_7SEG1_4_Pin, (0x08 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG1_5_GPIO_Port, LED_7SEG1_5_Pin, (0x04 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG1_6_GPIO_Port, LED_7SEG1_6_Pin, (0x02 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG1_7_GPIO_Port, LED_7SEG1_7_Pin, (0x01 & pattern_number[num]));
}

void display7SEG2(int num){
	//---0---
	//-5   1-
	//---6---
	//-4   2-
	//---3---
	HAL_GPIO_WritePin(LED_7SEG2_1_GPIO_Port, LED_7SEG2_1_Pin, (0x40 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG2_2_GPIO_Port, LED_7SEG2_2_Pin, (0x20 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG2_3_GPIO_Port, LED_7SEG2_3_Pin, (0x10 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG2_4_GPIO_Port, LED_7SEG2_4_Pin, (0x08 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG2_5_GPIO_Port, LED_7SEG2_5_Pin, (0x04 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG2_6_GPIO_Port, LED_7SEG2_6_Pin, (0x02 & pattern_number[num]));
	HAL_GPIO_WritePin(LED_7SEG2_7_GPIO_Port, LED_7SEG2_7_Pin, (0x01 & pattern_number[num]));
}

//- Global Functions -----------------------------
void update7SEG(int index){
	switch(index){
	case 0:
		display7SEG1(buffer_led[0]);
	    break;
	case 1:
		display7SEG1(buffer_led[1]);
	    break;
	case 2:
		display7SEG2(buffer_led[2]);
		break;
	case 3:
		display7SEG2(buffer_led[3]);
		break;
	default:
		break;
	}
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, !(0 == index || 2 == index));
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, !(1 == index || 3 == index));
}

void toggle7SEG(uint8_t num){
	switch(index_led & num){
	case 0:
		update7SEG(1);
		update7SEG(3);
		index_led = 1;
		break;
	case 1:
		update7SEG(0);
		update7SEG(2);
		index_led = 0;
		break;
	default:
		break;
	}
}
