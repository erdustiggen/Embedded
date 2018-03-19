NVIC can be used to give priority for interrupts. 
I am using a struct defined in misc.h, which gives control of the IRQ, and you can change priorety. 
Two different types of priority, Preemption and Sub. Preemtion used first, but if two has the same 
preemtion priority, you can seperate them by using subpiority. Both take values between 0x00 and 0x0F.
The lower the number, the higher the priority.

Lets say that UART1 is more important than UART2, then you can set the struct as following:

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
