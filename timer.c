#include "timer.h"

void Inict(void) {
	//puerto
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;  
    GPIOA->CRL &= ~(0xF << (0 * 4));    
    GPIOA->CRL |= (0xB << (0 * 4));  
	//timer
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;        
    TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; 
    TIM2->CCER |= TIM_CCER_CC1E;                        
    TIM2->CR1 |= TIM_CR1_ARPE; 
    TIM2->CR1 |= TIM_CR1_CEN;  
}

void Pulsot(void) {
		TIM2->PSC = 7199;   
    TIM2->ARR = 199; 
    TIM2->CCR1 = 10;
}

