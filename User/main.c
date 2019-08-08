/**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: main.c
**��   ��   ��: zhengyouxin
**����޸�����: 
**��        ��: �������ļ�
** �̼�����Ϣ��V1.0           
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
*���Ź���ʼ������
*prer:��Ƶ����0-7����3λ��Ч
*��Ƶ���ӣ�4*2^prer�����256
*rlr:��װ�ؼĴ���ֵ����11λ��Ч
*Tout=((4*2^prer)*rlr)/40 (ms)
*/
void IWDG_Init(u8 prer,u16 rlr)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); // ʹ�ܶԼĴ���IWDG_PR��IWDG_RLR�Ĳ���
    IWDG_SetPrescaler(prer);    //����IWDGԤ��Ƶֵ:prer
    IWDG_SetReload(rlr);        //����IWDG����ֵ
    IWDG_ReloadCounter();       //��������ֵ������IWDG������
    IWDG_Enable();              //ʹ��IWDG
}

/**
 * ι��
 */
void IWDG_Feed(void)
{
    IWDG_ReloadCounter();    /*reload*/
}

void NVIC_Configuration(void)
{              
	NVIC_InitTypeDef NVIC_InitStructure;   
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;           //���ô���2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;          //�����ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //ʹ���ж�
	NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;           //���ô���3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //�����ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //ʹ���ж�
	NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;           //���ô���1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //�����ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //ʹ���ж�
	NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;             //���ö�ʱ��3ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //�����ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //ʹ��
	NVIC_Init(&NVIC_InitStructure);
    
}

void sys_init(void)
{
	delay_init(72);
	NVIC_Configuration();
	//IWDG_Init(4,625);   //(4*2^4)*625/40 ms = 1s ���Ź���ʱ1s
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

	printf("����ST_VC������key���Գ���.....\r\n");
	Usart2_SendData(str,sizeof(str));
	
	IWDG_Feed();

	ControlDemo_EnterGUI();
	
	/* Infinite loop */
	while (1)
	{
		//Test_Demo();
		
		ZidongModeRun();//�Զ�ģʽ
		data_Process();	//����ģʽ
		
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
