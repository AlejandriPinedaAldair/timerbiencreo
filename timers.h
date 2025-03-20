#ifndef TIMERS_H
#define TIMERS_H

#include "stm32f10x.h"

void TIM2_Init(void);
void TIM2_SetPulse(uint16_t pulse_ms);

#endif