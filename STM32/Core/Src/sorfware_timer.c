/*
 * sorfware_timer.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ADMIN
 */
#include "sorfware_timer.h"

int timer_counter1 = 0;
int timer1_flag = 0;
int timer2_flag = 0;
int status =-1;

void setTimer1(int duration){
	timer_counter1 = duration;
	status = -1;
}
void timerRun(){
	if(timer_counter1 > 0 ){
		timer_counter1--;
		if(timer_counter1 == 150){
			status = 1;
		}
		if(timer_counter1 == 100){
			status = 2;
		}
		if(timer_counter1 == 50){
			status = 3;
		}
		if(timer_counter1 <= 0){
			status = 0;
		}
	}
}
