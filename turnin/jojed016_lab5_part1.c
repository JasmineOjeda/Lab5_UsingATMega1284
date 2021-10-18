/*	Author: Jasmine Ojeda jojed016@urc.edu
 *	Lab Section: 022
 *	Assignment: Lab 5  Exercise 1
 *	Exercise Description: Fuel level sensor with LEDs and seatbelt sensor included
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;

    DDRC = 0xFF; PORTC = 0x00;

    unsigned char tmp_A = 0x00;
    unsigned char tmp_C = 0x00;
    unsigned char tmp_empty = 0x00;

    /* Insert your solution below */
    while (1) {
        tmp_A = (~PINA) & 0x0F;

	/* Fuel level */
	if (tmp_A >= 13) {
            tmp_C = 0x3F;
	}
	else if (tmp_A >= 10) {
            tmp_C = 0x3E;
	}
	else if (tmp_A >= 7) {
            tmp_C = 0x3C;
	}
	else if (tmp_A >= 5) {
            tmp_C = 0x38;
        }
	else if (tmp_A >= 3) {
            tmp_C = 0x30;
        }
	else if (tmp_A >= 1) {
            tmp_C = 0x20;
        }
	else {
            tmp_C = 0x00;
	}

	/* Low fuel icon */
        if (tmp_A <= 4) {
            tmp_empty = 0x40;
	}
	else {
            tmp_empty = 0x00;
	}

	PORTC = tmp_C | tmp_empty;
    }

    return 0;
}
