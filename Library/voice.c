/*---------------------------------------------------
	voice.c (v1.00)
	ͨ�������ļ�
---------------------------------------------------*/

#include "main.h"
#include "port.h"

#include "voice.h"
#include "Delay.h"
#include "communication.h"

/*------ private variable --------------------------*/
tByte key_rotate_on_speech_number = 1;		// ѭ�������ο�������

extern bit flashing_flag;
   
/*--------------------------------------------------
	SC_Speech()
	�������������壬���ɱ��ڼ���������
---------------------------------------------------*/
void SC_Speech(tByte cnt)
	{
	tByte ii;
	SC_RST = 0;
//	delay_ms(100);
	Delay_50ms();
	SC_RST = 1;
//	delay_ms(150);
	Delay_50ms();
	for(ii=0; ii < cnt; ii++)
		{
		SC_DATA = 1; 
		delay_us(20);
		SC_DATA = 0; 
		delay_us(20);
		}
	}

/*-------------------------------------------------
	noVoice()
	���ϵ��ʱ����ã�������������
--------------------------------------------------*/
void noVoice()
	{
	P14=0;
	SC_DATA = 0;
	SC_RST = 0;
	delay_us(350); 
	SC_RST = 1;
	delay_us(350);
	P14 = 1;
	}

/*----------------------------------------------------
	key_rotate_on_speech()
	Կ����ת��ON��������ʾ
-----------------------------------------------------*/
void key_rotate_on_speech(void)
	{
	switch(key_rotate_on_speech_number)
		{
		case 1:
			{
			voice_EN = 1;
			SC_Speech(26);  
			Delay(100);
			voice_EN = 0;
			key_rotate_on_speech_number = 1;
			}
		break;
		
		case 2:
			{
			voice_EN = 1;
			SC_Speech(14);  
			Delay(40);
			SC_Speech(12);  
			Delay(60);
			voice_EN = 0;
			key_rotate_on_speech_number = 1;			
			}
		break;
		}
	}
	
/*-----------------------------------------------------
	key_rotate_off_speech()
	Կ����ת��OFF��������ʾ
void key_rotate_off_speech(void)
	{
	voice_EN = 1;
	SC_Speech(13);
	Delay(40);
	voice_EN = 0;
	}
------------------------------------------------------*/

/*----------------------------------------------------
	motorBAT_low_speech()
	������ƿ����������С�޶�ֵ��������ʾ�������㡣
-----------------------------------------------------*/
void motorBAT_low_speech(void)
	{
	voice_EN = 1;
	SC_Speech(4);
	Delay(80);
	voice_EN = 0;
	}

/*----------------------------------------------------
	ID_speech()
	��һ��������������һ����ʾ����
--------------------------------------------------------*/
void ID_speech(void)
	{
	voice_EN = 1;
	SC_Speech(24); 
	Delay(30);
	voice_EN = 0;
	}

/*----------------------------------------------------
	Self_learn_speech()
	��һ��������������һ����ʾ����
--------------------------------------------------------*/
void Self_learn_speech(void)
	{
	voice_EN = 1;
	SC_Speech(25); 
	Delay(30);
	voice_EN = 0;
	flashing_flag = 0;
	}

/*----------------------------------------------------
	host_touch_speech()
	��һ��������������һ����ʾ����
--------------------------------------------------------*/
void host_touch_speech(void)
	{
	voice_EN = 1;
	SC_Speech(2);  
	Delay(90);
	voice_EN = 0;
	Delay(30);
	}

/*-----------------------------------------------------
	host_2ndtouch_speech()
	�ڶ��δ����������ٱ�һ����ʾ����
-------------------------------------------------------*/
void host_2ndtouch_speech(void)
	{
	voice_EN = 1;
	SC_Speech(17);  
	Delay(140);
	voice_EN = 0;
//	Delay(10);
	}
	
/*----------------------------------------------------
	stolen_alarm_speech()
	�ж�Ϊ������ʱ�򣬷�������������һ��
----------------------------------------------------*/
void stolen_alarm_speech1(void)
	{
	voice_EN = 1;
	SC_Speech(14); 
	Delay(80);
	voice_EN = 0; 
	}

/*----------------------------------------------------
	stolen_alarm_speech()
	�ж�Ϊ������ʱ�򣬷������������ڶ���
----------------------------------------------------*/
 void stolen_alarm_speech2(void)
	{
	voice_EN = 1;
	SC_Speech(3); 
	Delay(180);
	voice_EN = 0;
	Delay(20);
	}

/*----------------------------------------------------
	open_lock_speech()
	����������������ͨ����֤��������ʾ
-----------------------------------------------------*/
void open_lock_speech(void)
	{
	voice_EN=1;
	SC_Speech(15); 
	Delay(60);
	voice_EN=0;
	}

/*----------------------------------------------------
	close_lock_speech()
	�жϸ����뿪��������ʾ
-----------------------------------------------------*/
void close_lock_speech(void)
	{
	voice_EN = 1;
	SC_Speech(16);  
	Delay(60);
	voice_EN = 0;
	}

/*----------------------------------------------------
	battery_stolen_speech()
	������⵽��ƽ����ʱ��������ʾ��ƽ����
-----------------------------------------------------*/
void battery_stolen_speech(void)
	{
	voice_EN = 1;
	SC_Speech(13);  
	Delay(100);
	voice_EN = 0;
	}

/*----------------------------------------------------
	Cutting_Wire_Voice()
	���˼������ߵ�ʱ�򣬲���������
-----------------------------------------------------*/
void Cutting_Wire_Voice(void)
	{
	voice_EN = 1;
	SC_Speech(20);  
	Delay(120);
	voice_EN = 0;
	}

/*----------------------------------------------------
	Product_Test_Voice()
	���Գ����е�������ʾ
-----------------------------------------------------*/
void Product_Test_Voice(void)
	{
	voice_EN = 1;
	SC_Speech(19);  
	Delay(150);
	voice_EN = 0;
	}

/*---------------------------------------------------------------
	Battery_low_alarm_speech()
	���ڸ���������ص�������һ��ֵ��������ʾ
----------------------------------------------------------------*/
void Battery_low_alarm_speech(void)
	{
	voice_EN = 1;
	SC_Speech(9);
	Delay(80);
	voice_EN = 0;
	}

/*---------------------------------------------------------------
	Battery_high_alarm_speech()
	���ڸ�������������һ��ֵ��ʱ��������ʾ
----------------------------------------------------------------*/
void Battery_high_alarm_speech(void)
	{
	voice_EN = 1;
	SC_Speech(7);
	Delay(50);
	voice_EN = 0;
	}

/*-------------------------------------------------------------
	Alarm_stolen_speech()
	���ڸ�����������������
---------------------------------------------------------------*/
void Alarm_stolen_speech(void)
	{
	voice_EN = 1;
	SC_Speech(5);
	Delay(150);
	voice_EN = 0;
	}
	
/*--------------------------------------------------------------
	Alarm_raised_speech()
	���ڸ�����������̧�𱨾�
---------------------------------------------------------------*/
void Alarm_raised_speech(void)
	{
	voice_EN = 1;
	SC_Speech(3);
	Delay(140);
	voice_EN = 0;
	}
	
/*--------------------------------------------------------------
	Alarm_fell_speech()
	���ڸ������������ر���
----------------------------------------------------------------*/
void Alarm_fell_speech(void)
	{
	voice_EN = 1;
	SC_Speech(2);
	Delay(120);
	voice_EN = 0;
	}
	
/*---------------------------------------------------------------
	Host_battery_high_alarm_speech()
	���ڸ�������������������ʾ
---------------------------------------------------------------*/
void Host_battery_high_alarm_speech(void)
	{
	voice_EN = 1;
	SC_Speech(7);  
	Delay(80);
	voice_EN = 0;
	}

/*---------------------------------------------------------------
	battery_stolen_speech_F3()
	���ڸ�����������ر�������
---------------------------------------------------------------*/
void battery_stolen_speech_F3(void)
	{
	voice_EN = 1;
	SC_Speech(11);  
	Delay(50);
	voice_EN = 0;
	}
	
/*---------------------------------------------------------------
	wire_broken_speech(void)
	���ڸ������������߱����ϱ���
----------------------------------------------------------------*/
void wire_broken_speech(void)
	{
	voice_EN = 1;
	SC_Speech(15);  
	Delay(80);
	voice_EN = 0;	
	}

/*---------------------------------------------------------------
	lock_rotated_on_speech(void)
	���ڸ������������߱����ϱ���
----------------------------------------------------------------*/
void lock_rotated_on_speech(void)
	{
	voice_EN = 1;
	SC_Speech(12);  
	Delay(80);
	voice_EN = 0;	
	}
/*---------------------------------------------------------------
	lock_rotated_off_speech(void)
	���ڸ������������߱����ϱ���
----------------------------------------------------------------*/
void lock_rotated_off_speech(void)
	{
	voice_EN = 1;
	SC_Speech(13);  
	Delay(80);
	voice_EN = 0;	
	}

/*---------------------------------------------------
	end of file
----------------------------------------------------*/