#include "io_control.h"

#include "usart.h"
void turn_on_clocks(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN | RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM3EN;
}

void configure_io(void) {
    /* enable on board led */
    GPIOA->CRL |= GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1;
    GPIOA->CRL &= ~GPIO_CRL_CNF5 & ~GPIO_CRL_CNF5_1;
	// stackoverflow how to get time intervals on stm32
	// enable cycle counter
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CYCCNT = 0;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
	
	
	// PC12 / IN2  relay / red light
			GPIOC->CRH |= GPIO_CRH_MODE12_0 | GPIO_CRH_MODE12_1;
			GPIOC->CRH&= ~GPIO_CRH_CNF12_0 & ~GPIO_CRH_CNF12_1;
}

void control_green_onboard_led(unsigned int on_or_off) {
    /* off == 0, on == 1 */
    if (on_or_off == 0) {
        GPIOA->ODR &= ~(unsigned int)GPIO_ODR_ODR5;
    } else if (on_or_off == 1) {
        GPIOA->ODR |= GPIO_ODR_ODR5;
    }
}

uint8_t get_led_state(void) { return (GPIOA->ODR & GPIO_ODR_ODR5) >> 5; }

void delay(unsigned int wait_for) {
    for (unsigned int i = 0; i < wait_for; i++) {
        i = i * 1;
    }
}
