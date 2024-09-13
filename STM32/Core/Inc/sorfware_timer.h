/*
 * sorfware_timer.h
 *
 *  Created on: Sep 12, 2024
 *      Author: ADMIN
 */

#ifndef INC_SORFWARE_TIMER_H_
#define INC_SORFWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int status;

void setTimer1(int duration);
void setTimer2(int duration);
void timerRun();

#endif /* INC_SORFWARE_TIMER_H_ */
