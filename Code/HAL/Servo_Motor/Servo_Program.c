#include "../../MCAL/Timer/Timer_Interface.h"



void Servo_Init(){
	TIMERS_voidTimer1Init();
}

void Servo_SetAngle(u16 Servo_Angle){
	TIMERS_voidTIMER1SetCompareMatchValueA(Servo_Angle);
}
