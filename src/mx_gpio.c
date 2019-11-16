/**
  ******************************************************************************
  * File Name          : mx_gpio.c
  * Date               : 01/11/2019 16:33:25
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  *
  * COPYRIGHT 2019 STMicroelectronics
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "mx_gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

void mx_pinout_config(void) {
	/* Private typedef ---------------------------------------------------------*/
	GPIO_InitTypeDef GPIO_InitStruct;


	/** SPI1 GPIO Configuration	
		 PA5	 ------> SPI1_SCK
		 PA6	 ------> SPI1_MISO
		 PA7	 ------> SPI1_MOSI
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);


	/** SPI2 GPIO Configuration	
		 PC2	 ------> SPI2_MISO
		 PC3	 ------> SPI2_MOSI
		 PB10	 ------> SPI2_SCK
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOB, ENABLE);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOC, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOC, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF_SPI2);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource3, GPIO_AF_SPI2);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_SPI2);


	/** TIM3 GPIO Configuration	
		 PB0	 ------> TIM3_CH3
		 PB1	 ------> TIM3_CH4
		 PC6	 ------> TIM3_CH1
		 PC7	 ------> TIM3_CH2
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC, ENABLE);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOB, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOB, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOC, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);


	/** USART1 GPIO Configuration	
		 PA9	 ------> USART1_TX
		 PA10	 ------> USART1_RX
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);


	/** USART2 GPIO Configuration	
		 PA2	 ------> USART2_TX
		 PA3	 ------> USART2_RX
	*/


	/*Enable or disable the AHB1 peripheral clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);


	//!!! GPIO_Init is commented because some parameters are missing
	//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
	//GPIO_InitStruct.GPIO_Mode = ;
	//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	//GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);

	/*Configure GPIO pin alternate function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
