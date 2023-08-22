#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TIMERS_u8_TIMSK_REG				*((volatile u8 *)0x59)
#define TIMERS_u8_TIFR_REG				*((volatile u8 *)0x58)
#define TIMERS_u8_TCCR0_REG				*((volatile u8 *)0x53)
#define TIMERS_u8_TCNT0_REG				*((volatile u8 *)0x52)
#define TIMERS_u8_OCR0_REG				*((volatile u8 *)0x5C)

//Timer 1
#define TIMERS_u8_TCCR1A_REG			*((volatile u8 *)0x4F)
#define TIMERS_u8_TCCR1B_REG			*((volatile u8 *)0x4E)
#define TIMERS_u8_TCNT1H_REG			*((volatile u8 *)0x4D)
#define TIMERS_u8_TCNT1L_REG			*((volatile u8 *)0x4C)

#define TIMERS_u16_TCNT1_REG			*((volatile u16 *)0x4C)

#define TIMERS_u8_OCR1AH_REG			*((volatile u8 *)0x4B)
#define TIMERS_u8_OCR1AL_REG			*((volatile u8 *)0x4A)

#define TIMERS_u16_OCR1A_REG			*((volatile u16 *)0x4A)


#define TIMERS_u8_ICR1H_REG			*((volatile u8 *)0x47)
#define TIMERS_u8_ICR1L_REG			*((volatile u8 *)0x46)

#define TIMERS_u16_ICR1_REG			*((volatile u16 *)0x46)

/**************** Registers Pins Of Timer 0 *****************************/

#define TIMERS_TCCR0_WGM00_PIN			6
#define TIMERS_TCCR0_WGM01_PIN			3

#define TIMERS_TIMSK_TOIE0_PIN			0
#define TIMERS_TIMSK_TOIE1_PIN			1

#define TIMERS_TCCR0_CS00_PIN			0
#define TIMERS_TCCR0_CS01_PIN			1
#define TIMERS_TCCR0_CS02_PIN			2

#define TIMERS_COM00					4
#define TIMERS_COM01					5


/**************** Registers Pins Of Timer 1 *****************************/

#define TIMER1_WGM10					0
#define TIMER1_WGM11					1
#define TIMER1_WGM12					3
#define TIMER1_WGM13					4

// OC1A

#define TIMER1_COM1A0					6					
#define TIMER1_COM1A1					7	

// OC1B

#define TIMER1_COM1B0					4					
#define TIMER1_COM1B1					5	

#endif
