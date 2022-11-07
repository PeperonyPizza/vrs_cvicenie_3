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

#define GPIOA_BASE_REG 			*((volatile uint32_t *)(GPIOA_BASE_ADDR))

//MODER register
#define	GPIOA_MODER_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x00U))
//OTYPER register
#define	GPIOA_OTYPER_REG		*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x04U))
//OSPEEDER register
#define GPIOA_OSPEEDER_REG		*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x08U))
//PUPDR register
#define GPIOA_PUPDR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x0CU))
//IDR register
#define GPIOA_IDR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x10U))
//ODR register
#define GPIOA_ODR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x14U))
//BSRR register
#define GPIOA_BSRR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x18U))
//BRR register
#define GPIOA_BRR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR + 0x28U))

//RCC base address
#define	RCC_BASE_ADDR			(uint32_t)(0x40021000U)
//AHB offset
#define	AHB_OFFSET				(uint32_t)(0x00000014U)

#define AHB_REGISTER			*((volatile uint32_t *)(GPIOA_BASE_ADDR + AHB_OFFSET))

//AHBEN register
#define	RCC_AHBENR_REG			*((volatile uint32_t *) (uint32_t)(RCC_BASE_ADDR + 0x00000014U))

/* LED and button macros */
#define LED_ON					GPIOA_BSRR_REG |= (1 << 4)   	//GPIOA pin 4
#define LED_OFF					GPIOA_BRR_REG |= (1 << 4)		//GPIOA pin 4


#define BUTTON_GET_STATE		*((volatile uint32_t *)((uint32_t)(0x48000000 + 0x10U)))

typedef enum
{
     NONE = 0,
     RISE = 1,
     FALL = 2
} EDGE_TYPE;


#endif /* ASSIGNMENT_H_ */
