/*------------------------------------------------------------------*-
   DDC-Z.c (v1.00)
  ------------------------------------------------------------------
   COPYRIGHT
  ---------
   This code is copyright (c) 2015 by Richard Zhang.
-*------------------------------------------------------------------*/

#include "Main.h"
#include "Port.h"

#include "hSch51.h"
#include "Timer.h"
#include "Elecmotor.h"
#include "Button.h"
#include "UART.h"
#include "communication.h"
#include "Speech.h"
#include "Function.h"
#include "Sensor.h"
#include "Alarm.h"
#include "Battery.h"
#include "Function.h"
#include "Function-S.h"
#include "DDC-Locktest-Function.h"

/* ............................................................... */
void main(void)
   {
	// Initialize all tasks
	Speech_Init();
	UART_Init(BAUD9600);
	Timer0_Init(500);   
	Elecmotor_Init();
	Button_Init();
	Battery_Init();
	Sensor_Init();
	Alarm_Init();
	Function_init();
	Function_S_init();
	Locktest_init();
	
   // Add Tasks
   hSCH_Add_Task(Elecmotor_update, 1000, 1, 1);		// 1ms/ticket
   hSCH_Add_Task(Button_update, 1500, 200, 1);		// 100ms/ticket
   hSCH_Add_Task(Speech_update, 1500, 1000, 1);		// 0.5s/ticket
//   hSCH_Add_Task(Sensor_update, 2000, 1, 1);			// 1ms/ticket
	hSCH_Add_Task(Alarm_update, 3000, 2000, 1);		// 1s/ticket
   hSCH_Add_Task(Function_update, 1500, 4000, 1);	// 2s/ticket
   hSCH_Add_Task(Function_s_update, 2000, 1, 1);	// 1ms/ticket
   hSCH_Add_Task(Locktest_update_1, 200, 27000, 1);		// 12.5s/ticket
   hSCH_Add_Task(Locktest_update_2, 15000, 27000, 1);		// 12.5s/ticket
   hSCH_Add_Task(Locktest_update_3, 2000, 1, 1);		// 12.5s/ticket
	
	// Start the program.
	hSCH_Start();
	while(1)
      {
		// Excute the program.
		hSCH_Dispatch_Tasks();
		}
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/