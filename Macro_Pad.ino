//**************************************************************//
//	Project:			Custom key/macro pad					//
//	Author:				Luno Konick								//
//	Date:				12 Sept, 2019							//
//	Version:			0.1										//
//	Notes:														//
//	Hardware:			# Cherry or Cherry Compatible mechanical//
//						switches, # Shift Registers (), [TYPE]	//
//						Display, Rotery Encoder					//
//	Printed Bits:		THINGIVERSE URL GOES HERE				//
//**************************************************************//

//****Included Libraries****//
#include <Keyboard.h>
//****Variable Declaration****//
//Constants
	//IO Pins
		//Shift Register control pins
		const int latchPin	= 1;
		const int dataPin	= 2;
		const int clockPin	= 3;
		//Rotary Encoder Pins
		const int rotPinA	= 4;
		const int rotPinB	= 5;

//Variables
	//Shift Register variables
	byte switchVar1			= 73;				//Shift Register input, this value should translate to 01001001
	byte switchVar2			= 170;
	byte switchVar3			= 255;
	//Button Input Variables
	bool but01C				= false;			//Button 1 Current read value
	bool but01P				= false;			//Button 1 Previous loop value
	bool but02C				= false;			//Button 2 Current read value
	bool but02P				= false;			//Button 2 Previous loop value
	bool but03C				= false;			//Button 3 Current read value
	bool but03P				= false;			//Button 3 Previous loop value
	bool but04C				= false;			//Button 4 Current read value
	bool but04P				= false;			//Button 4 Previous loop value
	bool but05C				= false;			//Button 5 Current read value
	bool but05P				= false;			//Button 5 Previous loop value
	bool but06C				= false;			//Button 6 Current read value
	bool but06P				= false;			//Button 6 Previous loop value
	bool but07C				= false;			//Button 7 Current read value
	bool but07P				= false;			//Button 7 Previous loop value
	bool but08C				= false;			//Button 8 Current read value
	bool but08P				= false;			//Button 8 Previous loop value
	bool but09C				= false;			//Button 9 Current read value
	bool but09P				= false;			//Button 9 Previous loop value
	bool but10C				= false;			//Button 10 Current read value
	bool but10P				= false;			//Button 10 Previous loop value
	bool but11C				= false;			//Button 11 Current read value
	bool but11P				= false;			//Button 11 Previous loop value
	bool but12C				= false;			//Button 12 Current read value
	bool but12P				= false;			//Button 12 Previous loop value
	bool but13C				= false;			//Button 13 Current read value
	bool but13P				= false;			//Button 13 Previous loop value
	bool but14C				= false;			//Button 14 Current read value
	bool but14P				= false;			//Button 14 Previous loop value
	bool but15C				= false;			//Button 15 Current read value
	bool but15P				= false;			//Button 15 Previous loop value
	bool but16C				= false;			//Button 16 Current read value
	bool but16P				= false;			//Button 16 Previous loop value
	bool but17C				= false;			//Button 17 Current read value
	bool but17P				= false;			//Button 17 Previous loop value
	bool but18C				= false;			//Button 18 Current read value
	bool but18P				= false;			//Button 18 Previous loop value
	bool but19C				= false;			//Button 19 Current read value
	bool but19P				= false;			//Button 19 Previous loop value
	bool but20C				= false;			//Button 20 Current read value
	bool but20P				= false;			//Button 20 Previous loop value
	int curModeA;								//Rotary Encoder Pin A Current read value
	int lastModeA;								//Rotary Encoder Pin A Previous loop value
	int curModeB;								//Rotary Encoder Pin B Current read value
	int lastModeB;								//Rotary Encoder Pin B Previous loop value
	int encPos;									//Rotary Encoder Current Position
	int encPosLast;								//Rotary Encoder Previous Position
	int layer				= 0;				//Macro Layer value
	int layerP				=layer;				//Macro Layer delta check variable
 
void setup() {									// Put your setup code here, to run once at system start/reset:
	Serial.begin( 9600 );						//Standard Serial connection Baude rate
	//Pin definitions
	pinMode( latchPin, OUTPUT );				//Set latchPin to Output to control Shift Register
	pinMode( clockPin, OUTPUT );				//Set clockPin to Output to control Shift Register
	pinMode( dataPin, INPUT );					//Set dataPin to Input to read data from Shift Register
	pinMode(rotPinA, INPUT);					//Set rotPinA to Input to read data from Rotary Encoder
	pinMode(rotPinB, INPUT);					//Set rotPinB to Input to read data from Rotary Encoder
	lastModeA				= LOW;				//Set initial value for variable
	lastModeB				= LOW;				//Set initial value for variable
	curModeA				= LOW;				//Set initial value for variable
	curModeB				= LOW;				//Set initial value for variable
	encPos					= 0;				//Set initial value for variable
	encPosLast				= 0;				//Set initial value for variable
}

void loop() {									// put your main code here, to run repeatedly:
	//***Shift Register section***//
	latchPulse( latchPin );						//Call lathcPulse function to 
	switchVar1 = shiftIn( dataPin, clockPin );	//Run function to read in first Shift Register byte
	switchVar2 = shiftIn( dataPin, clockPin );	//Run function again immidiatly to read in next Shift Register byte
	switchVar3 = shiftIn( dataPin, clockPin );	//Run function again immidiatly to read in next Shift Register byte
	// rpls 1 start
	checkByte( switchVar1, 1 );				//Call checkByte function with swithVar1 byte, sending a 1 to denote the register being checked
	checkByte( switchVar3, 3 );				//Call checkByte function with swithVar3 byte, sending a 3 to denote the register being checked
	checkByte( switchVar2, 2 );				//Call checkByte function with swithVar2 byte, sending a 2 to denote the register being checked
	// rpls 1 end
	if ( but01C == but01P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but01C == true && but01P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but01P = but01C;
	}
	if ( but02C == but02P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but02C == true && but02P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but02P = but02C;
	}
	if ( but03C == but03P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but03C == true && but03P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but03P = but03C;
	}
	if ( but04C == but04P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but04C == true && but04P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but04P = but04C;
	}
	if ( but05C == but05P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but05C == true && but05P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but05P = but05C;
	}
	if ( but06C == but06P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but06C == true && but06P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but06P = but06C;
	}
	if ( but07C == but07P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but07C == true && but07P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but07P = but07C;
	}
	if ( but08C == but08P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but08C == true && but08P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but08P = but08C;
	}
	if ( but09C == but09P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but09C == true && but09P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but09P = but09C;
	}
	if ( but10C == but10P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but10C == true && but10P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but10P = but10C;
	}
	if ( but11C == but11P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but11C == true && but11P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but11P = but11C;
	}
	if ( but12C == but12P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but12C == true && but12P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but12P = but12C;
	}
	if ( but13C == but13P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but13C == true && but13P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but13P = but13C;
	}
	if ( but14C == but14P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but14C == true && but14P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but14P = but14C;
	}
	if ( but15C == but15P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but15C == true && but15P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but15P = but15C;
	}
	if ( but16C == but16P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but16C == true && but16P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but16P = but16C;
	}
	if ( but17C == but17P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but17C == true && but17P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but17P = but17C;
	}
	if ( but18C == but18P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but18C == true && but18P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but18P = but18C;
	}
	if ( but19C == but19P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but19C == true && but19P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but19P = but19C;
	}
	if ( but20C == but20P ) {	}			//Check to see if the button value has changed
	else {									//If the values do not match alter sent keypress
		if ( but20C == true && but20P == false)
		{
			switch ( layer ) {
				case 0:
					Keyboard.press( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.press( 'Q' );
					break;
				case 2:
					Keyboard.press( KEY_LEFT_ALT );
					Keyboard.press( 'M' );
					break;
				default: ;
			}
			
		}
		else {
			switch ( layer ) {
				case 0:
					Keyboard.release( KEY_RIGHT_CTRL );
					break;
				case 1:
					Keyboard.release( 'Q' );
					break;
				case 2:
					Keyboard.release( KEY_LEFT_ALT );
					Keyboard.release( 'M' );
					break;
				default: ;
			}
		}
		but20P = but20C;
	}
	//Encoder check code
	// read the current state of the current encoder's pins
	curModeA = digitalRead( encPinA );
	curModeB = digitalRead( encPinB );
	// compare the four possible states to figure out what has happened
	//   then encrement/decrement the current encoder's position
	if (curModeA != lastModeA) {
		if (curModeA == LOW) {
			if (curModeB == LOW) {
				encPos--;
			}
			else {
				encPos++;
			}
		}
		else {
			if (curModeB == LOW) {
				encPos++;
			}
			else {
				encPos--;
			}
		}
	}
	if (curModeB != lastModeB[c]) {
		if (curModeB == LOW) {
			if (curModeA == LOW) {
				encPos++;
			}
			else {
				encPos--;
			}
		}
		else {
			if (curModeA == LOW) {
				encPos--;
			}
				else {
				encPos++;
			}
		}
	}
	// set the current pin modes (HIGH/LOW) to be the last know in modes
	//   for the next loop to compare to
	lastModeA = curModeA;
	lastModeB = curModeB;
	// if this encoder's position changed, flag the change variable so we
	//   know about it later
	if (encPos != encPosLast) {
		change = 1;
	}

	if (change == 1) {
		// if an encoder has changed, do something with that information
		// here, I am just going to print all the encoder's positions
		// debounce - if there has been a change, wait for a bit (so to speak) to let the
		//   bounces settle - change to your liking
		delay(100);
	}
}

void latchPulse( int myLatchPin ) {			//Function call to pulse latchPin value for 20 microseconds to read button values from Shift Register
	digitalWrite( myLatchPin, 1 );			//Write myLatchPin High to tell Shift Register to read inputs to register
	delayMicroseconds( 20 );				//Wait briefly to allow the Shift Regester to gather the inputs.
	digitalWrite( myLatchPin, 0 );			//Write myLatchPin Low to tell the Shift Register to send the read values
}

//************shiftIn***************//
//	To call the following function	//
//	for subsiquent conntected		//
//	Shift Registers, call the		//
//	function back to back. It will	//
//	read one byte at at time from	//
//	each connected register.		//
//	Reads down the chain starting	//
//	with the closest connected		//
//	register and onward down the	//
//	chain.							//
//**********************************//
byte shiftIn( int myDataPin, int myClockPin ) {//Function to take the bits streamed from the Shift Regester and output a byte
	//myDataPin and myClockPin are both pased in to the function on call
	int i;									//temp counter variable used by for loop
	int temp = 0;							//temporary variable used to pass data
	int pinState;							//debugging value used to track data transmission
	byte myDataIn = 0;						//Temproary variable used to hold data

	pinMode( myClockPin, OUTPUT );			//Sets mode for myClockPin to Output
	pinMode( myDataPin, INPUT );			//Sets mode for myDataPin to Input

	for (i=7; i>=0; i--)					//For loop that counts down from the last bit to the first bit in the byte, as they are read from the Shift Register in reverse order to the way they are arranged in a byte
	{
		digitalWrite( myClockPin, 0);		//Bring myClockPin Low to start transmision
		delayMicroseconds( 0.2 );			//Very small delay
		temp = digitalRead( myDataPin );	//Read from the myDataPin to get the current bit being transmitted
		if ( temp ) {						//If the temp variable contains a nonzero value
			pinState = 1;					//set debugging value to 1
			myDataIn = myDataIn | ( 1 << i );//Flip the bit corrisponding to the slot that lines up with the counter in the myDataIn byte
		}
		else {								//If the temp bariable contains a zero
			pinState = 0;					//set debugging value to 0
		}
		digitalWrite( myClockPin, 1 );		//Bring myClockPin High, signafying the end of the pulse in the read
	}
	return myDataIn;						//Returns the gathered data to the function call in the main code
}

void checkByte( byte myByte, int whichRegister ) {//Function to check the passed byte for pressed buttons
	if ( myByte == B00000000 ) {			//Check to see if myByte is empty, avoid unnecessary processing if so

	}
	else	{								//If myByte is not empty check which buttons are pressed
		if ( myByte & ( 1 << 0 ) ) {		//Check the first byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but01C = true;
				break;
			case 2:
				but09C = true;
				break;
			case 3:
				but17C = true;
				break;
			default: ;
			}
		}
		if	( myByte & ( 1 << 1 ) ) {		//Check the second byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but02C = true;
				break;
			case 2:
				but10C = true;
				break;
			case 3:
				but18C = true;
				break;
			default: ;
			}
		}
		if	( myByte & ( 1 << 2 ) ) {		//Check the third byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but03C = true;
				break;
			case 2:
				but11C = true;
				break;
			case 3:
				but19C = true;
				break;
			default: ;
			}
		}
		if	( myByte & ( 1 << 3 ) ) {		//Check the fourth byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but04C = true;
				break;
			case 2:
				but12C = true;
				break;
			case 3:
				but20C = true;
				break;
			default: ;
			}
		}
		if	( myByte & ( 1 << 4 ) ) {		//Check the fifth byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but05C = true;
				break;
			case 2:
				but13C = true;
				break;
			case 3:
				break;
			default: ;
			}
		}
		if	( myByte & ( 1 << 5 ) ) {		//Check the sixth byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but06C = true;
				break;
			case 2:
				but14C = true;
				break;
			case 3:
				break;
			default: ;
			}
		}
		if	( myByte & ( 1 << 6 ) ) {		//Check the seventh byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but07C = true;
				break;
			case 2:
				but15C = true;
				break;
			case 3:
				break;
			default: ;
			}
		}
		if	( myByte & ( 1 << 7 ) ) {		//Check the eighth byte of myByte to see if the button is pressed
			switch ( whichRegister ) {
			case 1:
				but08C = true;
				break;
			case 2:
				but16C = true;
				break;
			case 3:
				break;
			default: ;
			}
		}
	}
}








// rplc 1
//	if ( switchVar1 == B00000000 ) {	//Check to see if switchVar1 is empty, avoid unnecessary processing if so
//
//	}
//	else	{													 //If switchVar1 is not empty check which buttons are pressed
//		if ( switchVar1 & ( 1 << 0 ) ) {//Check the first byte of switchVar1 to see if the button is pressed
//			but01C = true;
//		}
//		if	( switchVar1 & ( 1 << 1 ) ) {//Check the second byte of switchVar1 to see if the button is pressed
//			but02C = true;
//		}
//		if	( switchVar1 & ( 1 << 2 ) ) {//Check the third byte of switchVar1 to see if the button is pressed
//			but03C = true;
//		}
//		if	( switchVar1 & ( 1 << 3 ) ) {//Check the fourth byte of switchVar1 to see if the button is pressed
//			but04C = true;
//		}
//		if	( switchVar1 & ( 1 << 4 ) ) {//Check the fifth byte of switchVar1 to see if the button is pressed
//			but05C = true;
//		}
//		if	( switchVar1 & ( 1 << 5 ) ) {//Check the sixth byte of switchVar1 to see if the button is pressed
//			but06C = true;
//		}
//		if	( switchVar1 & ( 1 << 6 ) ) {//Check the seventh byte of switchVar1 to see if the button is pressed
//			but07C = true;
//		}
//		if	( switchVar1 & ( 1 << 7 ) ) {//Check the eighth byte of switchVar1 to see if the button is pressed
//			but08C = true;
//		}
//	}
//	if ( switchVar2 == B00000000 ) {	//Check to see if switchVar2 is empty, avoid unnecessary processing if so
//
//	}
//	else	{													 //If switchVar2 is not empty check which buttons are pressed
//		if ( switchVar2 & ( 1 << 0 ) ) {//Check the first byte of switchVar2 to see if the button is pressed
//			but09C = true;
//		}
//		if	( switchVar2 & ( 1 << 1 ) ) {//Check the second byte of switchVar2 to see if the button is pressed
//			but10C = true;
//		}
//		if	( switchVar2 & ( 1 << 2 ) ) {//Check the third byte of switchVar2 to see if the button is pressed
//			but11C = true;
//		}
//		if	( switchVar2 & ( 1 << 3 ) ) {//Check the fourth byte of switchVar2 to see if the button is pressed
//			but12C = true;
//		}
//		if	( switchVar2 & ( 1 << 4 ) ) {//Check the fifth byte of switchVar2 to see if the button is pressed
//			but13C = true;
//		}
//		if	( switchVar2 & ( 1 << 5 ) ) {//Check the sixth byte of switchVar2 to see if the button is pressed
//			but14C = true;
//		}
//		if	( switchVar2 & ( 1 << 6 ) ) {//Check the seventh byte of switchVar2 to see if the button is pressed
//			but15C = true;
//		}
//		if	( switchVar2 & ( 1 << 7 ) ) {//Check the eighth byte of switchVar2 to see if the button is pressed
//			but16C = true;
//		}
//	}
//	if ( switchVar3 == B00000000 ) {	//Check to see if switchVar3 is empty, avoid unnecessary processing if so
//
//	}
//	else	{													 //If switchVar3 is not empty check which buttons are pressed
//		if ( switchVar3 & ( 1 << 0 ) ) {//Check the first byte of switchVar3 to see if the button is pressed
//			but17C = true;
//		}
//		if	( switchVar3 & ( 1 << 1 ) ) {//Check the second byte of switchVar3 to see if the button is pressed
//			but18C = true;
//		}
//		if	( switchVar3 & ( 1 << 2 ) ) {//Check the third byte of switchVar3 to see if the button is pressed
//			but019C = true;
//		}
//		if	( switchVar3 & ( 1 << 3 ) ) {//Check the fourth byte of switchVar3 to see if the button is pressed
//			but20C = true;
//		}
//		if	( switchVar3 & ( 1 << 4 ) ) {//Check the fifth byte of switchVar3 to see if the button is pressed
//			
//		}
//		if	( switchVar3 & ( 1 << 5 ) ) {//Check the sixth byte of switchVar3 to see if the button is pressed
//			
//		}
//		if	( switchVar3 & ( 1 << 6 ) ) {//Check the seventh byte of switchVar3 to see if the button is pressed
//			
//		}
//		if	( switchVar3 & ( 1 << 7 ) ) {//Check the eighth byte of switchVar3 to see if the button is pressed
//			
//		}
//	}
//