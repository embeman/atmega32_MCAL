#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include <TIMER/Timer_Types.h>
#include <Std_Types.h>

void Timer_init();

void Timer_SetTimer0_OVF_Callback(Timer_Interrupt_P2F);
void Timer_SetTimer0_OCR_Callback(Timer_Interrupt_P2F);

void Timer_SetOCR0(uint8 ocr0);
void Timer_SetTCNT0(uint8 tcnt0);

#endif
