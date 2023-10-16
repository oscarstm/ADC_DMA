#include "stm32f4xx.h"

#include "clk_user.h"
#include "delay_user.h"
#include "pinout.h"
#include "adc_user.h"
#include "adc_setting.h"
#include "adc_dma.h"
#include "adc_dmaSetting.h"

uint16_t memData[1];

int main(void) {
	// settings
	clk_user();
	GPIOC_Init();
	ADC1_Init();
	DMA2_ADC1_Init();
	ADC1_En();
	ADC1_Start();
	// Process
	DMA2_Setting((uint32_t) memData, 1);

	while (1) {

		if (memData[0] <= 2000) {
			GPIOC->ODR |= (GPIO_ODR_ODR_13);
		} else {
			GPIOC->ODR &= ~(GPIO_ODR_ODR_13);
		}
		delay(10);

	}

}

void DMA2_Stream4_IRQHandler(void) {

	if ((DMA2->HISR & DMA_HISR_TCIF4) == DMA_HISR_TCIF4) {
		DMA2->HIFCR |= (DMA_HIFCR_CTCIF4);
	} else if ((DMA2->HISR & DMA_HISR_TEIF4) == DMA_HISR_TEIF4) {
		//
	}

}
