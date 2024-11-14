/*
 * timer.c
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */

//--- main header --------------------------------

#include "timer.h"

//--- Variables ----------------------------------

//- Local Variables ------------------------------
int TIMECYCLE 		= 0;
int counter_one_sec = 0;

//--- Functions Definition -----------------------

void init_SoftwareTimer(uint32_t HCLK, uint32_t Prescaler, uint32_t Period){
	TIMECYCLE = ((1000 * (Prescaler + 1) * (Period + 1)) / (HCLK));
}

void set_one_sec_timer(){

}

void timer_Run(){

}

