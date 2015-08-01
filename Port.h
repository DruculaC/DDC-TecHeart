/*------------------------------------------------------------------*-
   Port.H (v1.00)
  ------------------------------------------------------------------
   'Port Header'

   COPYRIGHT
   ---------
   This code is copyright (c) 2001 by Richard.
-*------------------------------------------------------------------*/

// ------ Sch51.C ----------------------------------------

// Comment this line out if error reporting is NOT required
// #define SCH_REPORT_ERRORS

// #ifdef SCH_REPORT_ERRORS
// The port on which error codes will be displayed
// ONLY USED IF ERRORS ARE REPORTED
// #define Error_port P2
// #endif

// ------ Elecmotor.c -------------------------------------------------
// P2.2, P2.3: PIN13, PIN14, control the electronic motor to locking and unlocking the motor bike.
sbit MagnetCon1 = P2^2;
sbit MagnetCon2 = P2^3;

// ------ Button.c -------------------------------------------------
// P2.5, PIN16, read the motor key's status.
sbit Key_switch = P2^5;


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



