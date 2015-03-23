/*-------------------------------------------------------------
	operation.c
	�����������
--------------------------------------------------------------*/

#include "main.h"
#include "port.h"

#include "operation.h"
#include "other.h"
#include "voice.h"
#include "battery.h"
#include "delay.h"
#include "ElecMotor.h"

/*------ private variable --------------------------*/
bit enable_sensor_delayEN = 0;		// �ӳ�ʹ�ܴ�������ʹ�ܣ����ܼ�ʱʹ�ܴ���������Ҫ��һ��ʱ��		

/*------- Public variable declarations --------------------------*/
extern bit position_sensor_EN;  	
extern bit fell_flag;						
extern bit raised_flag;				
extern tByte sensor_trigger_count;	
extern tByte sensor_1ststage_count;	
extern bit raised_fell_once_flag;			
extern bit raised_fell_flag;					
extern bit host_stolen_alarm1_EN;     
extern bit host_stolen_alarm2_EN;      
extern tByte host_stolen_alarm1_count;		
extern tByte host_stolen_alarm2_count;		
extern bit stolen_alarm_flag;					
extern tWord sensor_3rdstage_time;			
extern tByte sensor_3rdstage_effcount;		
extern tByte sensor_3rdstage_count;			
extern tWord sensor_3rdstage_interval;		
extern tWord sensor_2ndstage_time;		
extern tByte sensor_2ndstage_count;		
extern tWord ADC_check_result;		
extern tByte wire_broken_count;		
extern bit wire_broken_flag;			
extern bit battery_stolen_EN;			
extern tByte battery_stolen_count;
extern bit sensor_3rdalarm_flag;
extern tByte enable_sensor_delay_count;		
extern bit Silence_Flag;
extern tByte key_rotated_on_flag;		
extern tByte IDkey_certificated_times;

/*-----------------------------------------
	slave_away_operation()
	
	operation for slave is away
------------------------------------------*/
void slave_away_operation(void)
	{
	// handle with battery status
	if((Silence_Flag == 0))
		verifybattery(ADC_check_result);
	
	// turn off the magnet 
	ElecMotor_ACW();
	
	if(Silence_Flag == 0)
		// speech for slave away
		close_lock_speech();	
	
	// enable_sensor();	
	enable_sensor_delayEN = 1;
	enable_sensor_delay_count = 0;
	// delay time, avoid sensor trigger on.
	Delay(20);
	IDkey_certificated_times = 0;

	if(Silence_Flag == 1)
		Silence_Flag = 0;
		

	}

/*----------------------------------------------------------------------
		slave_nearby_operation()
		operation for slave is nearby
----------------------------------------------------------------------*/
void slave_nearby_operation(void)
	{

    if(Silence_Flag == 0)
		{
		// speech for slave nearby
		open_lock_speech();
		
		// rotate on speech
		key_rotate_on_speech();		
		}
	// flag key rotation status
	key_rotated_on_flag = 1;

	}
	
/*---------------------------------------------------
	end of file
----------------------------------------------------*/
