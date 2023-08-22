#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

// Timer 0
void TIMERS_voidTimer0Init(void);
u8 TIMERS_u8TIMER0SetCallBack(void(*Copy_pf)(void));
u8 TIMERS_u8TIMER0CTCSetCallBack(void(*Copy_pf)(void));
void TIMERS_voidTIMER0SetCompareMatchValue(u8 Copy_u8OCR0Value);
void TIMERS_voidTIMER0SetPreload(u8 Copy_u8PreloadValue);


// Timer 1
void TIMERS_voidTimer1Init(void);
void TIMERS_voidTIMER1SetCompareMatchValueA(u16 Copy_u8OCR1Value);
void TIMERS_voidTIMER1SetTimerValue(u16 Copy_u8OCR1Value);
u16 TIMERS_u16TIMER1ReadTimerValue(void);

#endif
