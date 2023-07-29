#include <TIMER/Timer.h>
#include <TIMER/Timer_Cfg.h>
#include <TIMER/Timer_Reg.h>
#include <avr/interrupt.h>

Timer_Interrupt_P2F _timer0_ovf_isr;
Timer_Interrupt_P2F _timer0_ocr_isr;

void Timer_SetTCNT0(uint8 tcnt0){
	_TCNT0 = tcnt0;
}

void Timer_SetOCR0(uint8 ocr0){
	_OCR0 = ocr0;
}

void Timer_SetTimer0_OVF_Callback(Timer_Interrupt_P2F timer0_OVF_ISR){
	_timer0_ovf_isr =timer0_OVF_ISR;
}

void Timer_SetTimer0_OCR_Callback(Timer_Interrupt_P2F timer0_OCR_ISR){
	_timer0_ocr_isr =timer0_OCR_ISR;
}

static void Timer0_Enable_OVF_Interrupt(){
	_TIMSK |= 1<<0;// enable overflow interrupt
}

static void Timer0_Enable_OCR_Interrupt(){
	_TIMSK |= 1<<1;// enable overflow interrupt
}

void Timer_init(){

	// Enabling Over Flow interrupt for Timer 0
	#if TIMER0_OCR_INTERRUPT == 1
		Timer0_Enable_OVF_Interrupt();
	#endif
	// Enabling Over Flow interrupt for Timer 0
	#if TIMER0_OCR_INTERRUPT == 1
		Timer0_Enable_OCR_Interrupt();
	#endif


	// setting up timer0
	Timer_SetTCNT0(TIMER0_TCNT0);


	#if		TIMER0_MODE_SELECT == TIMER0_MODE_NORMAL
		_TCCR0 &=~(1<<6);
		_TCCR0 &=~(1<<3);
	#elif 	TIMER0_MODE_SELECT == TIMER0_MODE_PWM_PHASE
		_TCCR0 |= (1<<6);
		_TCCR0 &=~(1<<3);
	#elif 	TIMER0_MODE_SELECT == TIMER0_MODE_CTC
		_TCCR0 &=~(1<<6);
		_TCCR0 |= (1<<3);
	#elif	TIMER0_MODE_SELECT == TIMER0_MODE_PWM_FAST
		_TCCR0 |= (1<<6);
		_TCCR0 |= (1<<3);
	#endif


	// Set Pre-Scaler for Timer0
	_TCCR0  &=~(1<<0 | 1<<1 | 1<<2);
	_TCCR0 |= TIMER0_PRESCALER_SELECT;

}

ISR(TIMER0_OVF_vect){
	if(_timer0_ovf_isr !=0)
		_timer0_ovf_isr();
	_TCNT0 = 0x00;
}

ISR(TIMER0_COMP_vect){
	if(_timer0_ocr_isr != 0)
		_timer0_ocr_isr();
	_TCNT0 = 0x00;
}

