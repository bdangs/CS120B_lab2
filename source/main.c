/*Author: Bryan Dang
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include “simAVRHeader.h”
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char cntavail;
	while(1) {
	// 1) Read input
		tmpA = PINA & 0x0F;
		// 2) Perform computation
		if (tmpA == 0x01) {
			cntavail += 1;
		} 
		if (tmpA == 0x02){
			cntavail += 1;
		}
		if (tmpA == 0x04){
			cntavail += 1;
		}
		if (tmpA == 0x08){
			cntavail += 1;
		}
		// 3) Write output
		PORTC = cntavail;
	}
	return 0;
}

