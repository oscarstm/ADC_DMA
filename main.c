#include "stm32f4xx.h"

#include "clk_user.h"
#include "pinout_user.h"
#include "delay_user.h"
#include "adc_user.h"
#include "dma_user.h"


uint16_t memData[1];

void ADC1_En(void) {
	ADC1->CR2 |= (ADC_CR2_ADON);
	delay(100);
}


void ADC1_Start(void) {
	ADC1->SR = 0;
	ADC1->CR2 |= (ADC_CR2_SWSTART);
}


void DMA2_Setting(uint32_t srcPer, uint32_t destMem, uint16_t size) {
	DMA2_Stream4->NDTR = size ;
	DMA2_Stream4->PAR = srcPer ;
	DMA2_Stream4->M0AR = destMem;

	DMA2_Stream4->CR |= (DMA_SxCR_EN);
}

int main ()
{
	clk_user();

	ADC1_Init();

	ADC1_En();

	DMA2_Init();

	DMA2_Setting((uint32_t) &ADC1->DR, (uint32_t) memData, 1);

	ADC1_Start();

	while (1)
	{


	}

}
