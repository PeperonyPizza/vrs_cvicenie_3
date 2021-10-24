/*
 * assignment.h
 *
 *  Created on: 27. 9. 2020
 *      Author: Stancoj
 */

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

/**
 * 		This header file provides macros to the MCU's registers required for this assignment.
 * 		Your task is to provide their actual implementation so you can use them in application in "main.c"
 * 		and make your "LED blink" application code readable and great again!
 */

//GPIOA peripheral base address
#define	GPIOA_BASE_ADDR			(uint32_t)(0x48000000U)
//GPIOB peripheral base address
#define	GPIOB_BASE_ADDR			(uint32_t)(0x48000400U)
//MODER register
#define	GPIOB_MODER_REG			*(uint32_t *)(GPIOB_BASE_ADDR + 0x00U)
//OTYPER register
#define	GPIOB_OTYPER_REG		*(uint32_t *)(GPIOB_BASE_ADDR + 0x04U)
//OSPEEDER register
#define GPIOB_OSPEEDER_REG		*(uint32_t *)(GPIOB_BASE_ADDR + 0x08U)
//PUPDR register
#define GPIOB_PUPDR_REG			*(uint32_t *)(GPIOB_BASE_ADDR + 0x0CU)
//IDR register
#define GPIOB_IDR_REG			*(uint32_t *)(GPIOB_BASE_ADDR + 0x10U)
//ODR register
#define GPIOB_ODR_REG			*(uint32_t *)(GPIOB_BASE_ADDR + 0x14U)
//BSRR register
#define GPIOB_BSRR_REG			*(uint32_t *)(GPIOB_BASE_ADDR + 0x18U)
//BRR register
#define GPIOB_BRR_REG			*(uint32_t *)(GPIOB_BASE_ADDR + 0x28U)

//RCC base address
#define	RCC_BASE_ADDR			(uint32_t)(0x40021000U)
//AHB offset
#define	AHB_OFFSET				(uint32_t)(0x00000014U)

//AHBEN register
#define	RCC_AHBENR_REG			*((volatile uint32_t *) (uint32_t)(RCC_BASE_ADDR + 0x00000014U))

/* LED and button macros */
#define LED_ON					*((volatile uint32_t *)((uint32_t)(0x48000000 + 0x18U))) |= (1 << 4)   	//GPIOB pin 4
#define LED_OFF					*((volatile uint32_t *)((uint32_t)(0x48000000 + 0x28U))) |= (1 << 4)		//GPIOB pin 4

#define BUTTON_GET_STATE		!(*((volatile uint32_t *)((uint32_t)(0x48000000 + 0x10U))) & (1 << 3))

typedef enum
{
     NONE = 0,
     RISE = 1,
     FALL = 2
} EDGE_TYPE;


static EDGE_TYPE edgeDetect(uint8_t pin_state, uint8_t samples);


#endif /* ASSIGNMENT_H_ */
