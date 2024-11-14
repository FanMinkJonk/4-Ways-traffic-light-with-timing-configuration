/*
 * fsm_traffic_mode.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "fsm_traffic_mode.h"

//--- Variables ----------------------------------

//- Global Variables -----------------------------
uint8_t status_traffic = 0;
uint8_t status_light   = 0;

//- Private Variables ----------------------------
uint8_t pattern_light = 0;

uint8_t red 		  = 5;
uint8_t amber 		  = 2;
uint8_t green 		  = 3;
uint8_t counter_red   = 5;
uint8_t counter_amber = 2;
uint8_t counter_green = 3;

//--- Functions Definition -----------------------

//- Private Functions ----------------------------
void config_leds(uint8_t pattern){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, 	 LED_RED_1_Pin,   (0x20 & pattern));
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, (0x10 & pattern));
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, (0x08 & pattern));
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, 	 LED_RED_2_Pin,   (0x04 & pattern));
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, (0x02 & pattern));
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, (0x01 & pattern));
}

//- Init Traffic Modes ---------------------------
void init_auto_mode(void){
	counter_red   = red;
	counter_amber = amber;
	counter_green = green;
	buffer_led[0] = counter_red / 10;
	buffer_led[1] = counter_red % 10;
	buffer_led[2] = counter_green / 10;
	buffer_led[3] = counter_green % 10;
	flag_l 		  = 0;
	flag_seg 	  = 0;
	toggle7SEG(0);
	config_leds(0x1e);
	set_one_sec_timer();
}

void init_red_config_mode(void){
	buffer_led[0] = 0 / 10;
	buffer_led[1] = 2 % 10;
	buffer_led[2] = red / 10;
	buffer_led[3] = red % 10;
	flag_seg 	  = 0;
	counter_red   = red;
	flag_blinky_led = 0;
	toggle7SEG(0);
	config_leds(0x1b);
	set_one_sec_timer();
}

void init_amber_config_mode(void){
	buffer_led[0] = 0 / 10;
	buffer_led[1] = 3 % 10;
	buffer_led[2] = amber / 10;
	buffer_led[3] = amber % 10;
	flag_seg 	  = 0;
	counter_amber = amber;
	flag_blinky_led = 0;
	toggle7SEG(0);
	config_leds(0x2d);
	set_one_sec_timer();
}

void init_green_config_mode(void){
	buffer_led[0] = 0 / 10;
	buffer_led[1] = 4 % 10;
	buffer_led[2] = green / 10;
	buffer_led[3] = green % 10;
	flag_seg 	  = 0;
	counter_green = 0;
	flag_blinky_led = 0;
	toggle7SEG(0);
	config_leds(0x36);
	set_one_sec_timer();
}

//- Traffic Modes --------------------------------
void fsm_mode_auto(void){
	switch(status_light){
	case STATUS_RED_GREEN:
		config_leds(0x1e);
		if(flag_one_sec == 1){
			set_one_sec_timer();
			flag_l = (--counter_green == 0);
			--counter_red;
		}
		if(flag_l == 1){
			flag_l = 0;
			status_light = STATUS_RED_AMBER;
			counter_green = green;
			break;
		}
		if(flag_seg == 1){
			flag_seg = 0;
			buffer_led[0] = counter_red / 10;
			buffer_led[1] = counter_red % 10;
			buffer_led[2] = counter_green / 10;
			buffer_led[3] = counter_green % 10;
			toggle7SEG(1);
		}
		break;
	case STATUS_RED_AMBER:
		config_leds(0x1d);
		if(flag_one_sec == 1){
			set_one_sec_timer();
			flag_l = (--counter_amber == 0);
			--counter_red;
		}
		if(flag_l == 1){
			flag_l = 0;
			status_light = STATUS_GREEN_RED;
			counter_red = red;
			counter_amber = amber;
			break;
		}
		if(flag_seg == 1){
			flag_seg = 0;
			buffer_led[0] = counter_red / 10;
			buffer_led[1] = counter_red % 10;
			buffer_led[2] = counter_amber / 10;
			buffer_led[3] = counter_amber % 10;
			toggle7SEG(1);
		}
		break;
	case STATUS_GREEN_RED:
		config_leds(0x33);
		if(flag_one_sec == 1){
			set_one_sec_timer();
			flag_l = (--counter_green == 0);
			--counter_red;
		}
		if(flag_l == 1){
			flag_l = 0;
			status_light = STATUS_AMBER_RED;
			counter_green = green;
			break;
		}
		if(flag_seg == 1){
			flag_seg = 0;
			buffer_led[0] = counter_green / 10;
			buffer_led[1] = counter_green % 10;
			buffer_led[2] = counter_red / 10;
			buffer_led[3] = counter_red % 10;
			toggle7SEG(1);
		}
		break;
	case STATUS_AMBER_RED:
		config_leds(0x2b);
		if(flag_one_sec == 1){
			set_one_sec_timer();
			flag_l = (--counter_amber == 0);
			--counter_red;
		}
		if(flag_l == 1){
			flag_l = 0;
			status_light = STATUS_RED_GREEN;
			counter_red = red;
			counter_amber = amber;
			break;
		}
		if(flag_seg == 1){
			flag_seg = 0;
			buffer_led[0] = counter_amber / 10;
			buffer_led[1] = counter_amber % 10;
			buffer_led[2] = counter_red / 10;
			buffer_led[3] = counter_red % 10;
			toggle7SEG(1);
		}
		break;
	default:
		break;
	}
}

void mode_red_config(void){
	if(flag_i == 1){
		flag_i = 0;
		counter_red = (((++counter_red) == 100) ? 2 : counter_red);
	}
	if(flag_s == 1){
		flag_s = 0;
		red = counter_red;
	}
	if(flag_seg == 1){
		flag_seg = 0;
		buffer_led[2] = counter_red / 10;
		buffer_led[3] = counter_red % 10;
		toggle7SEG(1);
	}
}

//- Global Functions -----------------------------
void init_fsm_traffic_mode(){
	status_traffic = MODE_AUTO;
	status_light = STATUS_RED_GREEN;
	init_auto_mode();
}

void fsm_traffic_mode(void){
	switch(status_traffic){
	case MODE_AUTO:
		if(flag_m == 1){
			flag_m = 0;
			status_traffic = MODE_RED_CONFIG;
			init_red_config_mode();
			break;
		}
		//TODO
		fsm_mode_auto();
		break;
	case MODE_RED_CONFIG:
		if(flag_m == 1){
			flag_m = 0;
			status_traffic = MODE_AMBER_CONFIG;
			init_amber_config_mode();
			break;
		}
		//TODO
		if(flag_blinky_led == 1){
			flag_blinky_led = 0;
			HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
		}
		mode_red_config();
		break;
	case MODE_AMBER_CONFIG:
		if(flag_m == 1){
			flag_m = 0;
			status_traffic = MODE_GREEN_CONFIG;
			init_green_config_mode();
			break;
		}
		//TODO
		if(flag_blinky_led == 1){
			flag_blinky_led = 0;
			HAL_GPIO_TogglePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin);
			HAL_GPIO_TogglePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin);
		}
		break;
	case MODE_GREEN_CONFIG:
		if(flag_m == 1){
			flag_m = 0;
			status_traffic = MODE_AUTO;
			init_fsm_traffic_mode();
			break;
		}
		//TODO
		if(flag_blinky_led == 1){
			flag_blinky_led = 0;
			HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
		}
		break;
	default:
		break;
	}
	if(flag_one_sec == 1){
		set_one_sec_timer();
	}
}






