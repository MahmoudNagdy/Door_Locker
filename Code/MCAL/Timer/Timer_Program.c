#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "../DIO/DIO_Interface.h"

#include "Timer_Config.h"
#include "Timer_Private.h"

/* Global Pointer To Function for TIMER0 Overflow */
static void(*TIMERS_pfTIMER0OVF)(void) = NULL;

/* Global Pointer To Function for TIMER0 CTC */
static void(*TIMERS_pfTIMER0CTC)(void) = NULL;


void TIMERS_voidTimer0Init(void){
	/* Select Mode => Normal Mode*/
	#if TIMER_MODE == NORMAL_MODE
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM00_PIN);
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM01_PIN);
	/* Set Preload Value */
	TIMERS_u8_TCNT0_REG = 192;
	/* Enable Overflow Interrupt */	
	#if INTERRUPT_MODE == Overflow_Mode
	SET_BIT(TIMERS_u8_TIMSK_REG, TIMERS_TIMSK_TOIE0_PIN);
	#else if INTERRUPT_MODE == CTC_Mode
	SET_BIT(TIMERS_u8_TIMSK_REG, TIMERS_TIMSK_TOIE1_PIN);
	#endif
	#elif TIMER_MODE == CTC_MODE
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM00_PIN);
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM01_PIN);
	/* SET Compare Match Unit Register */
	TIMERS_u8_OCR0_REG = 99;
	/* Enable Overflow Interrupt */	
	#if INTERRUPT_MODE == Overflow_Mode
	SET_BIT(TIMERS_u8_TIMSK_REG, TIMERS_TIMSK_TOIE0_PIN);
	#else if INTERRUPT_MODE == CTC_Mode
	SET_BIT(TIMERS_u8_TIMSK_REG, TIMERS_TIMSK_TOIE1_PIN);
	#endif
	#elif TIMER_MODE == PWM_PHASE_CORRECT
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM00_PIN);
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM01_PIN);
	#if OC0_MODE == Inverting
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM01);
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM00);
	#elif OC0_MODE == Non_Inverting
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM01);
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM00);
	#endif
	#elif TIMER_MODE == PWM_FAST
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM00_PIN);
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_WGM01_PIN);
	#if OC0_MODE == Inverting
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM01);
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM00);
	#elif OC0_MODE == Non_Inverting
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM01);
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_COM00);
	#endif
	#endif
	
	
	/* Set Prescaler Value => clk / 8 */
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_CS00_PIN);
	SET_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_CS01_PIN);
	CLR_BIT(TIMERS_u8_TCCR0_REG, TIMERS_TCCR0_CS02_PIN);
}

void TIMERS_voidTimer1Init(void){
	/* Select Timer1 Mode => PWM Fact(14) */
	SET_BIT(TIMERS_u8_TCCR1A_REG, TIMER1_WGM11);
	CLR_BIT(TIMERS_u8_TCCR1A_REG, TIMER1_WGM10);
	SET_BIT(TIMERS_u8_TCCR1B_REG, TIMER1_WGM12);
	SET_BIT(TIMERS_u8_TCCR1B_REG, TIMER1_WGM13);
	
	/* Select HW Action on OCA1 pin => Non- Inverting */
	SET_BIT(TIMERS_u8_TCCR1A_REG, TIMER1_COM1A1);
	CLR_BIT(TIMERS_u8_TCCR1A_REG, TIMER1_COM1A0);
	
	/* Set Top Value in ICR1 */
	TIMERS_u16_ICR1_REG = 19999;
	
	/* Set Angle Of Servo Motor */
	TIMERS_u16_OCR1A_REG = Selected_Angle;
	
	/* Set Prescaler Value => clk / 8 */
	CLR_BIT(TIMERS_u8_TCCR1B_REG, TIMERS_TCCR0_CS00_PIN);
	SET_BIT(TIMERS_u8_TCCR1B_REG, TIMERS_TCCR0_CS01_PIN);
	CLR_BIT(TIMERS_u8_TCCR1B_REG, TIMERS_TCCR0_CS02_PIN);
}


u8 TIMERS_u8TIMER0SetCallBack(void(*Copy_pf)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL){
		TIMERS_pfTIMER0OVF = Copy_pf;
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}


u8 TIMERS_u8TIMER0CTCSetCallBack(void(*Copy_pf)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL){
		TIMERS_pfTIMER0CTC = Copy_pf;
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}


void TIMERS_voidTIMER0SetCompareMatchValue(u8 Copy_u8OCR0Value){

	TIMERS_u8_OCR0_REG = Copy_u8OCR0Value;
	
}

void TIMERS_voidTIMER0SetPreload(u8 Copy_u8PreloadValue){
	TIMERS_u8_TCNT0_REG = Copy_u8PreloadValue;
}

void TIMERS_voidTIMER1SetCompareMatchValueA(u16 Copy_u8OCR1Value){
	TIMERS_u16_OCR1A_REG = Copy_u8OCR1Value;
}

void TIMERS_voidTIMER1SetTimerValue(u16 Copy_u8OCR1Value){
	TIMERS_u16_TCNT1_REG = Copy_u8OCR1Value;
}

u16 TIMERS_u16TIMER1ReadTimerValue(void){
	return TIMERS_u16_TCNT1_REG;
}




/********************** ISR Of Timer0 Overflow ************************/

void __vector_11(void)		__attribute__((signal));

void __vector_11(void){
	static u16 Local_u16CounterOVF = 0;
	Local_u16CounterOVF++;
	if(Local_u16CounterOVF == 3907){
		/* Update Preload Value */
		TIMERS_u8_TCNT0_REG = 192;
		
		/* Clear Overflow Counter */
		Local_u16CounterOVF = 0;
		
		/* Call App Function */
		if(TIMERS_pfTIMER0OVF != NULL){
			TIMERS_pfTIMER0OVF();
		}
	}
}


/********************** ISR Of Timer0 CTC ************************/

void __vector_10(void)		__attribute__((signal));

void __vector_10(void){
	static u16 Local_u16CounterCTC = 0;
	Local_u16CounterCTC++;
	if(Local_u16CounterCTC == 10000){
		Local_u16CounterCTC = 0;
		/* Call App Function */
		if(TIMERS_pfTIMER0CTC != NULL){
			TIMERS_pfTIMER0CTC();
		}
	}
}





