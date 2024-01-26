#include "timer.h"



void timer_init(void) {
    TIM3->PSC = 1; // smallest for fastest counting, divide by 1
		TIM3->ARR = 0xFFFF;
    TIM3->EGR |= TIM_EGR_UG;
    //TIM3->SR &= ~TIM_SR_UIF;
    TIM3->CR1 |= TIM_CR1_DIR | TIM_CR1_CEN;  // start/enable timer, downcounter
	
		// default is not one pulse mode, continuous
		
	
}

uint16_t timer_start(void) {
	return TIM3->CNT;
	
}

uint16_t timer_stop(uint16_t start_time);

void timer_shutdown(void);