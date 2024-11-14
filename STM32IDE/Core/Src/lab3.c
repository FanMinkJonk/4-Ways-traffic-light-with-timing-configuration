/*
 * lab3.c
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "lab3.h"

//--- Variables ----------------------------------

uint8_t flag_l = 0;
uint8_t flag_m = 0;
uint8_t flag_i = 0;
uint8_t flag_s = 0;

uint8_t flag_one_sec 	= 0;
uint8_t flag_seg 		= 0;
uint8_t flag_blinky_led = 0;

//--- Functions Definition -----------------------

void init_lab3(uint32_t Prescaler, uint32_t Period){
	init_SoftwareTimer(HAL_RCC_GetHCLKFreq(), // Return HCLK Frequency
					   Prescaler,  			  // Return TIM2 Prescaler
					   Period);	 			  // Return TIM2 Period
	init_fsm_traffic_mode();
	set_one_sec_timer();
}

void run_lab3(){
	fsm_traffic_mode();
	fsm_input_processing();
}

//--- INTERRUPT TIMER ----------------------------

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timer_Run();
	button_reading();
}



