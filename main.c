
#include "herder.h"


Uint16 r_cmd,r_val;
Uint16 rBuffer[8];

void CanHanle(void)
{
	r_cmd = 0; r_val=0;
	if( get_cmd_data(&r_cmd,&r_val, rBuffer) )
	{
		if ( (r_cmd>=0x50)&&(r_cmd<=0x5F) )
		{			
			CanIapMode2_Handle(rBuffer);			
		}	
	}
}

void main( void )
{   
	init_bsp();
	for(;;)
	{
		if ( CpuTimer0.InterruptCount >30)
		{	
			TimerStop();
			app_goto_run();
		}
		else
		{
			CanHanle();
		}
	}
}






