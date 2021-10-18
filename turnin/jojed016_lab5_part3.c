/*      Author: Jasmine Ojeda jojed016@ucr.edu
 *      Lab Section: 022
 *      Assignment: Lab 5  Exercise 3
 *      Exercise Description: https://youtu.be/488pLmdQOlg
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {START, WAIT, OFF, S1, S2, S3, ON, ALT1, ALT2, ALT3, PRESS} state;

unsigned char count = 0x00;

void Tick() {
    unsigned char tmp_A = (~PINA) & 0x01;
    /* State transitions */
    switch(state) {
        case START:
            state = WAIT;
            break;
        case WAIT:
            state = WAIT;

	    if (tmp_A == 0x01) {
                if (count == 0) {
                    state = S1;
	        }
		else if (count == 0x01) {
                    state = S2;
                }
		else if (count == 0x02) {
                    state = S3;
                }
                else if (count == 0x03) {
                    state = ON;
                }
                else if (count == 0x04) {
                    state = ALT1;
                }
                else if (count == 0x05) {
                    state = ALT2;
                }
                else if (count == 0x06) {
                    state = ALT3;
                }
                else if (count == 0x07) {
                    state = OFF;
                }
            }
            break;
	case S1:
	    state = PRESS;
	    break;
	case S2:
            state = PRESS;
            break;
	case S3:
            state = PRESS;
            break;
	case ON:
            state = PRESS;
            break;
	case ALT1:
            state = PRESS;
            break;
	case ALT2:
            state = PRESS;
            break;
	case ALT3:
            state = PRESS;
            break;
	case OFF:
            state = PRESS;
            break;
	case PRESS:
	    state = PRESS;
            if (tmp_A == 0x00) { state = WAIT;}
	    break;
	default:
	    break;
    }

    /* State actions */
    switch(state) {
        case START:
	    count = 0x00;
            PORTC = 0xFF;
            break;
	case WAIT:
	    break;
        case S1:
	    count++;
            PORTC = 0x21;
            break;
        case S2:
	    count++;
            PORTC = 0x12;
            break;
        case S3:
	    count++;
            PORTC = 0x0C;
            break;
        case ON:
	    count++;
            PORTC = 0x3F;
            break;
        case ALT1:
	    count++;
            PORTC = 0x15;
            break;
        case ALT2:
	    count++;
            PORTC = 0x2A;
            break;
        case ALT3:
	    count++;
            PORTC = 0x15;
            break;
        case OFF:
	    count = 0;
            PORTC = 0x00;
            break;
	default:
	    break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    state = START;
    /* Insert your solution below */
    while (1) {
        Tick();
    }
    return 1;
}
