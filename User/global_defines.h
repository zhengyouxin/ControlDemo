/**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: global_defines.h
**��   ��   ��: zhengyouxin
**����޸�����: 
**��        ��: �궨��ͷ�ļ�
** �̼�����Ϣ��V1.0           
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

