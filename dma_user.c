/*
 * dma_user.c
 *
 *  Created on: Sep 18, 2023
 *      Author: oscar
 */

#include "dma_user.h"

void DMA2_Init(void) {
	RCC->AHB1ENR |= (RCC_AHB1ENR_DMA2EN);

	DMA2_Stream4->CR &= ~(DMA_SxCR_DIR_0);
	DMA2_Stream4->CR &= ~(DMA_SxCR_DIR_1);

	DMA2_Stream4->CR |= (DMA_SxCR_CIRC);
	DMA2_Stream4->CR |= (DMA_SxCR_MINC);

	DMA2_Stream4->CR |= (DMA_SxCR_MSIZE_0);
	DMA2_Stream4->CR &= ~(DMA_SxCR_MSIZE_1);

	DMA2_Stream4->CR |= (DMA_SxCR_PSIZE_0);
	DMA2_Stream4->CR &= ~(DMA_SxCR_PSIZE_1);

	DMA2_Stream4->CR &= ~(DMA_SxCR_CHSEL_0);
	DMA2_Stream4->CR &= ~(DMA_SxCR_CHSEL_1);
	DMA2_Stream4->CR &= ~(DMA_SxCR_CHSEL_2);
}
