// This won't work, but an example for how to use it.

#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
#include "misc.h"
#include"stm32f4xx_usart.h"

NVIC_InitTypeDef NVIC_InitStruct;
 
NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
NVIC_Init(&NVIC_InitStruct);
 
NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
NVIC_Init(&NVIC_InitStruct);

//This will handle ALL interrupts which are enabled for USART1
//so you have to find first which one was triggered
void USART1_IRQHandler(void) {
    //Check if interrupt was because data is received
    if (USART_GetITStatus(USART1, USART_IT_RXNE)) {
        //Do your stuff here
        
        //Clear interrupt flag
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}

int main() {
// Do something

}
