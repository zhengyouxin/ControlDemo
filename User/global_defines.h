/**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: global_defines.h
**创   建   人: zhengyouxin
**最后修改日期: 
**描        述: 宏定义头文件
** 固件库信息：V1.0           
**
**------------------------------------------------------------------------------------------------------*/
#ifndef GLOBAL_DEFINES_H
#define GLOBAL_DEFINES_H

#include "stm32f10x.h"

typedef struct global_key_t{
	
	u16 Count;
	u8	Value;
	u16 ShortPressDown;
	u16 LongPressDown;
	
}GLOBAL_KEY_T;

typedef enum{
	MODE_LIANJI=0x01,
	MODE_SHOUDONG,
	MODE_ZIDONG,

}WORK_MODE;


#endif

