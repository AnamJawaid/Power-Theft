#include<P89V51RD2.H>
#include<pro_alcd.c>
#include<pro_uart.c>
#include<PGSM.c>
//#include<adc.c>
sbit current_pulse=P1^7;
sbit bulb=P1^7;
//sbit PULSE_Relay=P0^2;
//sbit oil_level=P1^1;
//sbit ir=P1^3;
int count1;
//sbit t1=P3^2;
//sbit gas=P1^0;
int Voltage1;

//idata unsigned char Disp_Line1[17]="PULSE=000";
//idata unsigned char Disp_Line2[17]="TEMP = 000 %";

int i=0;
int count;
int flag=0;
//int temp=0;
void Device_Init( void );

void main()
{ 
	//t1=0;
	//t2=0;
	
	//PULSE_Relay=0;
	//bulb=0;	
	Device_Init();
	GSM_Init( );
	UART_ST( "AT+CNMI=2,2,0,0,0\r\n");
	MSDelay(1000);
	//temp=0;
	count1=0;
	while(1)
	{
		
/*		
	if(ir==1)
{
	ALCD_Message( 0x01,   "" );
					ALCD_Message( 0x80,"INTRUDER DETECTED");
		//	MSDelay(1000);
			GSM_Send_SMS( Mb_Num, "INTRUDER DETECTED" ); 
		//GSM_Send_SMS( Mb_Num, "TEMP IS HIGH" );
		MSDelay(1000);
	ALCD_Message( 0x01,   "" );
}
		if(oil_level==1)
{
	ALCD_Message( 0x01,   "" );
					ALCD_Message( 0x80,"OIL LEVEL LOW");
			
			GSM_Send_SMS( Mb_Num, "OIL LEVEL LOW" ); 
	MSDelay(1000);
	ALCD_Message( 0x01,   "" );
}	 

Voltage1=ADC09_Start( 0, 0 );
//Voltage1=(Voltage1-40);
		count1 = Voltage1;
			
		Disp_Line2[9] = (Voltage1%10)+48;
	//	Disp_Line4[16] = (Voltage1%10)+48;
		Voltage1 = Voltage1 / 10;
		Disp_Line2[8] = (Voltage1%10)+48;
	//	Disp_Line4[15] = (Voltage1%10)+48;
		Voltage1 = Voltage1 / 10;
		Disp_Line2[7] = (Voltage1%10)+48;
	   // MSDelay(1000);
		//	ALCD_Message( 0x01,   "" );
	  //ALCD_Message( 0xC0,Disp_Line2 );
		//	MSDelay(1000);
		//	ALCD_Message( 0x01,   "" );
			
				if(count1>=40)
				{
					ALCD_Message(0x01,"" );
			ALCD_Message(0x80,"TEMP IS HIGH" );
					GSM_Send_SMS( Mb_Num, "TEMP IS HIGH" );
			MSDelay(500);
					ALCD_Message( 0x01,   "" );
					
				}	


*/

		if(current_pulse==1 )
{ 
		int x, y;
	flag=0;

	
	while(x<=6000)
		{   
			while(y<180)
			{ 
				++y;
			if(current_pulse==1)
			{
			  ++count;
	      
	    //  temp=count;
	//Disp_Line1[8] = (temp%10)+48;
//	Disp_Line4[5] = (temp%10)+48;
//temp= temp / 10;
//Disp_Line1[7] = (temp%10)+48;
	//Disp_Line4[4] = (temp%10)+48;
//temp = temp / 10;
//Disp_Line1[6] = (temp%10)+48;
//ALCD_Message( 0xC0, Disp_Line1 );
				//ALCD_Message( 0x01,   "" );
	     
	    
			MSDelay(300);
		} 
	} 
			++x;
	     y=0;
	//flag2=1;
	} 

	if(count>1)
	{
		ALCD_Message( 0x01,   "" );
					ALCD_Message( 0x80,"POWER THEFT");
			MSDelay(1000);
			GSM_Send_SMS( Mb_Num, "POWER THEFT" ); 
		
	}
	if(x>=6000 && flag==0)
	{
		ALCD_Message( 0x01,   "" );
			//		ALCD_Message( 0x80,"X=0");
		//	MSDelay(1000);
    //ALCD_Message( 0xC0, Disp_Line1 );
		//ALCD_Message( 0x80,Disp_Line2 );
		//GSM_Send_SMS( Mb_Num,Disp_Line1  );
		MSDelay(1000);
	//		GSM_Send_SMS( Mb_Num,Disp_Line4  );
	//	MSDelay(800);
		//GSM_Send_SMS1( Mb_Num,Disp_Line4  );
		flag=1;
		count=0;
		x=0;
		ALCD_Message( 0x01, "" );
	}
	
}	
	
	
		
	
	
	
	
	
		
	}

}


	
//}
void Device_Init( void )
{
	xdata unsigned char UC_count = 0xFD;	// For 9600 Buad Rate

	EA = 0;
	

	
	

	ALCD_Init( );
	

	UART0M1_Tx_Init( );
	

		
	

		
		
		
				
	Timer1M2_Init( UC_count );
	
	EA = 1;	
	
	TR1 = 1;								
ALCD_Message( 0x80, "WELCOME" );


	MSDelay(1000);
	ALCD_Message( 0x01, "" );

										// 0.1 sec delay
	

}