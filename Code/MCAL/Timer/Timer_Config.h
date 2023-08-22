#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H


/* Timer Mode */

#define NORMAL_MODE				0
#define CTC_MODE				1
#define PWM_PHASE_CORRECT		2
#define PWM_FAST				3
#define TIMER_MODE				PWM_FAST


/* Interrupt Mode */
#define Overflow_Mode			0
#define CTC_Mode				1
#define INTERRUPT_MODE			CTC_Mode

/* OC0 Mode */
#define Inverting				0
#define Non_Inverting			1
#define OC0_MODE			Inverting


/* Servo Angles */
#define Angle_0					999
#define Angle_180				1999
#define Selected_Angle			Angle_180					

#endif
