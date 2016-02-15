/*------------------------------------------------------------------*-
   Delay.C (v1.00)
  ------------------------------------------------------------------
   Delay program for other program.

   COPYRIGHT
   ---------
   This code is copyright (c) 2001 by Richard Zhang.
-*------------------------------------------------------------------*/

#include "Main.h"
#include "Port.h"

#include "DDC-Locktest-Function.h"
#include "UART.h"
#include "Speech.h"
#include "Sensor.h"

// ------ Public variable definitions ------------------------------

// ------ Public variable declarations -----------------------------
extern bit ID_certificated_G;
extern bit Auto_close_G;
extern bit Silent_mode_G;
extern tByte Sensor_time;

// ------ Private variables ----------------------------------------

// ------ Private constants ----------------------------------------

/*------------------------------------------------------------------*-
  Locktest_update_1()
  Initialisation function for the switch library.
-*------------------------------------------------------------------*/
void Locktest_update_1(void)
	{
	if(Key_switch == 1)
		{
		Silent_mode_G = 1;
		ID_certificated_G = 1;
		}
	}

/*------------------------------------------------------------------*-
  Locktest_update_2()
  Initialisation function for the switch library.
-*------------------------------------------------------------------*/
void Locktest_update_2(void)
	{
	if(Key_switch == 1)
		{
		Silent_mode_G = 1;
		Auto_close_G = 1;
		}
	}

/*------------------------------------------------------------------*-
  Locktest_update_3()
  Initialisation function for the switch library.
-*------------------------------------------------------------------*/
void Locktest_update_3(void)
	{
	if((!Horizontal_sensor)&&(Key_switch == 0))
		{
		Sensor_time += 1;
		if(Sensor_time >= 1)
			{
			Sensor_time = 0;
			Goto_speech(Tick);
			}
		}
	}

/*------------------------------------------------------------------*-
  Locktest_init()
  Initialisation function for the switch library.
-*------------------------------------------------------------------*/
void Locktest_init(void)
	{
	Silent_mode_G = 1;
	ID_certificated_G = 0;
	Auto_close_G = 0;
	}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
