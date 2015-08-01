/*------------------------------------------------------------------*-
   A.C (v1.00)
  ------------------------------------------------------------------
   Simple switch interface code, with software debounce.

   COPYRIGHT
   ---------
   This code is copyright (c) 2001 by Richard Zhang.
-*------------------------------------------------------------------*/

#include "Main.h"
#include "Port.h"

#include "Elecmotor.h"

// ------ Public variable definitions ------------------------------

// ------ Public variable declarations -----------------------------

// ------ Private variables ----------------------------------------
// static bit LED_state_G;
tWord Rotate_time;
bit Rotate_CW_G;

tByte Magnet_code[3];
bit Coding_G;
tByte Code_time = 0;
tByte Byte_Index = 0;
tByte Bit_Index = 0;
 
// ------ Private constants ----------------------------------------
// SW_THRES must be > 1 for correct debounce behaviour
// #define SW_THRES (3)

/*------------------------------------------------------------------*-
  Elecmotor_Init()
  Initialisation function for Electronic motor's lock.
-*------------------------------------------------------------------*/
void Elecmotor_Init(void)
   {
	MagnetCon1 = 1;
	MagnetCon2 = 1;
	Magnet_code[0] = CmdHead;
	Magnet_code[1] = CmdAddress;
	Magnet_code[2] = CmdMode1;
	Coding_G = 0;
	}

/*------------------------------------------------------------------*-
  Elecmotor_Init()
  Initialisation function for Electronic motor's lock.
-*------------------------------------------------------------------*/
void Elecmotor_update(void)
   {	
	if(Coding_G == 1)
		{
		if(MagnetCon2 == 0)
			{
			// whether msb is 1, if yes, maintain 10ms, if not maintain 4ms.
			if((Magnet_code[Byte_Index] & 0x80) == 0x80)
				{
				Code_time += 1;
				if(Code_time >= 10)	// 5 tickets, about 10ms.
					{
					Code_time = 0;
					Bit_Index += 1;
					MagnetCon2 = 1;
					// move 1 bit to left.
					Magnet_code[Byte_Index] <<= 1;
					}
				}
			else
				{
				Code_time += 1;
				if(Code_time >= 4)	// 2 tickets, about 4ms.
					{
					Code_time = 0;
					Bit_Index += 1;
					MagnetCon2 = 1;
					Magnet_code[Byte_Index] <<= 1;
					}		
				}
			
			if(Bit_Index >= 8)
				{
				Bit_Index = 0;
				Byte_Index += 1;
				if(Byte_Index > 2)
					{
					Byte_Index = 0;
					MagnetCon2 = 1;
					Coding_G = 0;
					}
				}			
			}
		else
			{
			Code_time += 1;
			if(Code_time >= 4)
				{
				Code_time = 0;
				MagnetCon2 = 0;
				}
			}		
		}
	else
		{
		// if ratate CW, MagnetCon2 = 0, driving moto to turn CW.
		if(Rotate_CW_G == 1)
			{
			MagnetCon1 = 1;
			MagnetCon2 = 0;
			}
		else
			{
			MagnetCon1 = 0;
			MagnetCon2 = 1;
			}
			
		Rotate_time += 1;	
		if(Rotate_time >= 5000)
			{
			Rotate_time = 0;
			Rotate_CW_G = ~Rotate_CW_G;
			}		
		}	
	}


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
