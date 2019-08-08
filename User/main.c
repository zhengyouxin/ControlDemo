/**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: main.c
**创   建   人: zhengyouxin
**最后修改日期: 
**描        述: 主函数文件
** 固件库信息：V1.0           
**
**------------------------------------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

#include "led.h"
#include "delay.h"
#include "printf.h"
#include "key.h"
#include "TFT_demo.h"
#include "Lcd_Driver.h"
#include "GUI.h"
#include "Timer.h"
#include "global_defines.h"
#include "control_IO.h"
#include "data_Process.h"
#include "sst_flash.h"

extern u16 count;

/*
*看门狗初始化函数
*prer:分频数：0-7，低3位有效
*分频因子：4*2^prer，最大256
*rlr:重装载寄存器值，低11位有效
*Tout=((4*2^prer)*rlr)/40 (ms)
*/
void IWDG_Init(u8 prer,u16 rlr)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); // 使能对寄存器IWDG_PR和IWDG_RLR的操作
    IWDG_SetPrescaler(prer);    //设置IWDG预分频值:prer
    IWDG_SetReload(rlr);        //设置IWDG重载值
    IWDG_ReloadCounter();       //按照设置值，重载IWDG计数器
    IWDG_Enable();              //使能IWDG
}

/**
 * 喂狗
 */
void IWDG_Feed(void)
{
    IWDG_ReloadCounter();    /*reload*/
}

void NVIC_Configuration(void)
{              
	NVIC_InitTypeDef NVIC_InitStructure;   
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;           //设置串口2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;          //子优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //使能中断
	NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;           //设置串口3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //子优先级1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //使能中断
	NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;           //设置串口1中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //子优先级1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //使能中断
	NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;             //设置定时器3全局中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //子优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //使能
	NVIC_Init(&NVIC_InitStructure);
    
}

void sys_init(void)
{
	delay_init(72);
	NVIC_Configuration();
	//IWDG_Init(4,625);   //(4*2^4)*625/40 ms = 1s 看门狗定时1s
	IWDG_Init(4,3125);	//(4*2^4)*3125/40 ms = 5s
	
	USART1_Configuration();
	USART2_Configuration(9600);
	TIM3_Int_Init(9,7199);

}

void bsp_init(void)
{
	Lcd_Init();
  	key_init();
	control_IO_init();
	sst_flash_Init();

}


 /*
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{

    u8 keyValue=0;
	u8 str[]="uart2 test!!\r\n";

	sys_init();
	bsp_init();

	printf("创新ST_VC开发板key测试程序.....\r\n");
	Usart2_SendData(str,sizeof(str));
	
	IWDG_Feed();

	ControlDemo_EnterGUI();
	
	/* Infinite loop */
	while (1)
	{
		//Test_Demo();
		
		ZidongModeRun();//自动模式
		data_Process();	//联机模式
		
		keyValue = KeyScanGetNum();

		if(keyValue)
		{
			printf("keyValue:%d\r\n",keyValue);
			KeyScanRun(keyValue);
		}
		IWDG_Feed();
	}
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
