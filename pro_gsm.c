//--------------------------------------------------------------------------------------------------------------------
//	113_GSM.c
//--------------------------------------------------------------------------------------------------------------------

// AUTH:	i-quad
// DATE:	17/10/2012

// Target: PROJECT BOARD of PHILIPS P89V51RD2 ( PES-01-0809 )

// Tool chain: KEIL IDE

//--------------------------------------------------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------
// 16-bit SFR Definitions for "P89V51RD2"
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
// Global VARIABLES
//--------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------
// Global CONSTANTS
//------------------------------------------------------------------------------------------------------------------

code unsigned char GSM_Send_SMS_Comm[]="AT+CMGS=";
code unsigned char GSM_Rx_SMS_Comm[]="AT+CNMI=2,2,0,0,0";

code char GSM_SMS1[]="SYSTEM STARTS";


code char Mb_Num[]="9986168650";


//--------------------------------------------------------------------------------------------------------------------
// Function PROTOTYPES
//--------------------------------------------------------------------------------------------------------------------

void GSM_Init( void );

void UART_Tx_char( char Tx_char );
//void GSM_Rx_SMS( void );
//void SMS_Rx_Poll( void );
void GSM_Send_SMS( char *Mb_Num, char *SMS );

//--------------------------------------------------------------------------------------------------------------------
// void GSM_Init( void )
//--------------------------------------------------------------------------------------------------------------------
// Function Name:	void GSM_Init( void )
// Arguments	:	No arguments
// Return Value	:	No return value
// Description	:	This function is used to test the GSM module. If we send a command AT then
// the GSM module will reply OK.

void GSM_Init(  )
{
	UART_Tx_char( 'A' );
	UART_Tx_char( 'T' );
	UART_Tx_char( 0x0D );				// ASCII value of CARRIAGE RETURN
}


//--------------------------------------------------------------------------------------------------------------------
// void UART_Tx_char( char Tx_char )
//--------------------------------------------------------------------------------------------------------------------
// Function Name:	void UART_Tx_char( char Tx_char )
// Arguments	:	No arguments
// Return Value	:	No return value
// Description	:	This function is used to send a single char through UART. After sending 
// a char, if receiving is enabled, then the received 1 byte data will be in Rx_data. If Tx_char
// and Rx_char, both are equal, then it comes out of while loop.




//--------------------------------------------------------------------------------------------------------------------
// void GSM_Send_SMS( char *Mb_Num, char *SMS )
//--------------------------------------------------------------------------------------------------------------------
// Function Name:	void GSM_Send_SMS( char *Mb_Num, char *SMS )
// Arguments	:	2 arguments
// *Mb_Num -> it receives a base address of a string which contains a mobile number.
// *SMS -> it receives a base address of a string which contains a text message.
// Return Value	:	No return value
// Description	:	This function is used to send an SMS. 

void GSM_Send_SMS( char *Mb_Num, char *SMS )
{
	data unsigned char i;

// SMS send command	is sent through UART
	for( i=0; GSM_Send_SMS_Comm[i] != '\0'; i++ )
		UART_Tx_char( GSM_Send_SMS_Comm[i] );
		
	Rx_count = 0;						// Take UART Receiver array to zeroth location
	
	//P2 = 0x22;							// Testing
	MSDelay(100);						// Testing

	UART_Tx_char( 0x22 );				// ASCII value of "
// Mobile number is sent through UART
	while( *Mb_Num != '\0' )
		UART_Tx_char( *Mb_Num++ );
    
	Rx_count = 0;						// Take UART Receiver array to zeroth location
	
	//P2 = 0x33;							// Testing
	MSDelay(100);						// Testing

	UART_Tx_char( 0x22 );				// ASCII value of "
	UART_Tx_char( 0x0D );	

	
	// ASCII value of CARRIAGE RETURN
//	UART_Tx_char( 0x0A );				// ASCII value of LINE FEED

	Rx_count = 0;						// Take UART Receiver array to zeroth location

// Text message is sent through UART
	while( *SMS != '\0' )
		UART_Tx_char( *SMS++ );

	Rx_count = 0;						// Take UART Receiver array to zeroth location

	UART_Tx_char( 0x1A );				// ASCII value of CTRL + Z
	

	//P2 = 0x44;							// Testing
	MSDelay(100);						// Testing

}

void UART_Tx_char( char Tx_char )
{
	SBUF = Tx_char;					// UART transmission starts
	Rx_data = 0x00;
while( Rx_data != Tx_char )		// comparing Transmitted and Received character
	{
		;
}
	ALCD_Message( 0x80, "gsm");
}
//void GSM_Rx_SMS( void )
//{
	//data unsigned char i;
//	M_4052_Sel0 = 0;
//	M_4052_Sel1 = 0;

// SMS send command	is sent through UART
//	Rx_count = 0;						// Take UART Receiver array to zeroth location
	//for( i=0; GSM_Rx_SMS_Comm[i] != '\0'; i++ )
	//	UART_Tx_char( GSM_Rx_SMS_Comm[i] );
	 //SBUF=GSM_Rx_SMS_Comm[i];

//	Rx_ALCD( );
	//Rx_count = 0;						// Take UART Receiver array to zeroth location
	//SBUF=0x0D ;				// ASCII value of CARRIAGE RETURN
//	Rx_ALCD( );
//}

//void SMS_Rx_Poll( void )
//{
	//data unsigned char i, j; 

// At this stage, we assume that the SMS as been received.
// The received SMS contains lots of extra informations, which are not needed. So check for -->  22"	

//ALCD_Message( 0x80, "1" );			// Testing
// To retrive the mobile number of received SMS
	//i = 0;
	//while( Rx_data_arr[i] != '\0' )
	//{
	//	if( (Rx_data_arr[i] == '+') && (Rx_data_arr[i+1] == '9') && (Rx_data_arr[i+2] == '1'))
		//	break;
	
	//	i++;
	//}
// To store the mobile number of received SMS
	//i = i+3;
	//for( j=0; j<10; j++,i++ )
	//	Rx_Mob_Num[j] = Rx_data_arr[i];


//	i = 0;
	//while( Rx_data_arr[i] != '\0' )
	//{
		//if( (Rx_data_arr[i] == '2') && (Rx_data_arr[i+1] == '2') && (Rx_data_arr[i+2] == '"'))
		//	break;
		
	//	i++;
	//}

									// OFF Buzzer
// Here we are storing the SMS received at 5th location of array of structure.
// The received SMS format is -- Message(Max 30), 3 space
	//i = i+5;
	//j = i;
//	while( i<(j+6) )
	//{
// Scan for 3 space to come out of this while loop
	//	if( Rx_data_arr[i]=='Y' ) 
	//	{
			
		//	ALCD_Message( 0xC0, "SWITCH ON" );			
		//	MOTOR_1=1;
		//	MOTOR_2=0;

			//break;	
		//}
//	if( Rx_data_arr[i]=='C1' )
		//{
					
			//ALCD_Message( 0xC0, "CLOCKWISE 80" );			
		//	MOTOR_1=1;
			//MOTOR_2=0;
		//	PWM(80);
		//	break;	
	//	}
		
		//if( Rx_data_arr[i]=='A1' )
		//{
					
		//	ALCD_Message( 0xC0, "ANTICLOCKWISE 80" );			
		//	MOTOR_1=0;
		//	MOTOR_2=1;
		//	PWM(80);
			//break;	
		//}

	//	if( Rx_data_arr[i]=='C2' )
	//	{
					
		//	ALCD_Message( 0xC0, "CLOCKWISE 50" );			
		//	MOTOR_1=1;
			//MOTOR_2=0;
			//PWM(50);
			//break;	
	//	}
		
	//	if( Rx_data_arr[i]=='A2' )
	//				
	//		ALCD_Message( 0xC0, "ANTICLOCKWISE 50" );			
			//MOTOR_1=0;
		//	MOTOR_2=1;
			//PWM(50);
		//	break;	
		//}

		//if( Rx_data_arr[i]=='C3' )
		//{
					
			//ALCD_Message( 0xC0, "CLOCKWISE 30" );			
		//	MOTOR_1=1;
		//	MOTOR_2=0;
		//	PWM(30);
		//}
		
	//	if( Rx_data_arr[i]=='A3' )
		//{
					
		//	ALCD_Message( 0xC0, "ANTICLOCKWISE 30" );			
		//	MOTOR_1=0;
		//	MOTOR_2=1;
		//	PWM(30);
		//	break;	
	//	}


	//	if( Rx_data_arr[i]=='N' ) 
	//	{
		////	ALCD_Message( 0xC0, "SWITCH OFF" );
		//	MOTOR_1=0;
		//	MOTOR_2=0;
		
		//	break;	
	//	}
		 

		
		
	//}

//}
