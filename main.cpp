#include "mbed.h"

// globals


const char common = 'a';	// establish common anode logic


bool decPt = true; // decimal point display flag
	
int main() {
	
	DigitalIn data(p30,PullUp);	// wire to data pin
 
	DigitalIn reset(p28,PullUp); // wire to reset pin

	DigitalIn clk(p27,PullUp); // wire to clock	
	
}
void loop(){
// loop to control character data
for (int i = 0; i <= 15; i++){
    
	}
}
// alternate display of decimal point

// function to convert numbers to bits 
int myfuncNumbToBits(int number){
	switch(number){
		case 0:
			return 11111100;
		break;
		case 1:
			return 01100000;
		break;
		case 2:
			return 11011010;
		break;
		case 3:
			return 11110010;
		break;
		case 4:
			return 01100110;
		break;
		case 5:
			return 10110110;
		break;
		case 6:
			return 10111110;
		break;
		case 7:
			return 11100000;
		break;
		case 8:
			return 11111110;
		break;
		case 9:
			return 11110110;
		break;
		case 10:
			return 11101110;
		break;
		case 11:
			return 00111110;
		break;
		case 12:
			return 10011100;
		break;
		case 13:
			return 01111010;
		break;
		case 14:
			return 10011110;
		break;
		case 15:
			return 10001110;
		break;
		default:
			return 10010010; // error condition
		break;
	}
}

void myDisplayFunction(int eightBits){
	if(common == 'a'){
		// XOR all bits
		eightBits = eightBits ^ 1111111; 
	}
}

