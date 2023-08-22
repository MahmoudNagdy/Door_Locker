#ifndef APP_INCLUDES_H
#define APP_INCLUDES_H


#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/Global_Interrupt/GI_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/WDT/WDT_Interface.h"

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/DC_MOTOR/DC_Motor_Interface.h"
#include "../HAL/Stepper/Stepper_Interface.h"
#include "../HAL/Servo_Motor/Servo_Interface.h"
#include "../HAL/7Segment/SevenSegment_Interface.h"


#include<util/delay.h>

#include "../HAL/KEYPAD/Keypad_Interface.h"
#define F_CPU 16000000UL


#endif
