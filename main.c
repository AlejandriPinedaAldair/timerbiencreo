#include "timers.h"

int main(void) {
    // Inicializar el GPIO para el pin PA0 como salida de TIM2_CH1
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;  // aqui se habilita el reloj  en este caso para GPIOA
    GPIOA->CRL &= ~(0xF << (0 * 4));     // Limpiamos los bits de configuración para PA0
    GPIOA->CRL |= (0xB << (0 * 4));      // Aqui se configura la salida PA0 en  alternativo (TIM2_CH1)

    // Inicializar el TIM2
    TIM2_Init();

    while (1) {
        TIM2_SetPulse(1);  //aqui establecimos el pulso de 1 milisegundo

			// Espera aproximada de 20 ms (con jitter) ya que: 400,000×55.5 ns=22,200,000 ns o 22.2ms
        for (volatile uint32_t i = 0; i < 400000; i++) {}
    }

    return 0;
}