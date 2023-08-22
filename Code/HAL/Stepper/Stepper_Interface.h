#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

#include "../../LIB/STD_TYPES.h";

void Stepper_Init();

void ActivatePins1(u8 Copy_u8_1B, u8 Copy_u8_2B, u8 Copy_u8_3B, u8 Copy_u8_4B);
void ActivatePins2(u8 Copy_u8_1B, u8 Copy_u8_2B, u8 Copy_u8_3B, u8 Copy_u8_4B);

void SelectStepAngle(u16 angle, u8 Direction);


#endif
