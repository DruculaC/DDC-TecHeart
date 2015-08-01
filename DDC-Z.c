/*------------------------------------------------------------------*-
   Main.c (v1.00)
  ------------------------------------------------------------------
   COPYRIGHT
  ---------
   This code is copyright (c) 2001 by Richard Zhang.
-*------------------------------------------------------------------*/

#include "Main.h"
#include "Port.h"

#include "hSch51.h"
#include "Timer.h"
#include "PC_IO_T1.h"
#include "Elecmotor.h"
#include "Button.h"

/* ............................................................... */

void main(void)
   {
   // Init Timer 0.
	InitT0(500);
   Elecmotor_Init();
	
	// Set baud rate to 9600: generic 8051 version
   PC_LINK_IO_Init_T1(9600);

   // Add Task
   hSCH_Add_Task(Elecmotor_update, 1000, 1, 1);

   hSCH_Start();
   
	while(1)
      {
      hSCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/