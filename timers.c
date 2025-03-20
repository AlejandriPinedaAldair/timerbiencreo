#include "timers.h"

void TIM2_Init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;        // Habilitar el reloj para Timer 2

    TIM2->PSC = 7200 - 1;   // Aqui el prescaler se divide 72 MHz a 10 kHz 

    TIM2->ARR = 200 - 1; // auto-reload  para un período de 20 ms 

    TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; //PWM en el canal 1
    TIM2->CCER |= TIM_CCER_CC1E;                        //salida en canal 1

    TIM2->CR1 |= TIM_CR1_ARPE; // Auto-reload para evitar problemas de sincronizacion
    TIM2->CR1 |= TIM_CR1_CEN;  // timer habilitado
}

void TIM2_SetPulse(uint16_t pulse_ms) {
    uint16_t pulse_ticks = pulse_ms * 10; // Aqui se toma 0.1 ms por tick
    TIM2->CCR1 = pulse_ticks;
}