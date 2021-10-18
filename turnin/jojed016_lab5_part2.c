/*      Author: Jasmine Ojeda jojed016@ucr.edu
 *      Lab Section: 022
 *      Assignment: Lab 5  Exercise 2
 *      Exercise Description: Incrementer/Decrementer
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {START, WAIT, INCREMENT, DECREMENT, INC_PRESS, DEC_PRESS, RES_PRESS, RESET} state;

unsigned char tmp_A = 0x00;

void Tick() {
    tmp_A = (~PINA) & 0x03;
    /* State transitions */
    switch(state) {
        case START:
            PORTC = 0x07;
            state = WAIT;
            break;
        case WAIT:
            if (tmp_A == 0x00) {
                state = WAIT;
            }
            else if (tmp_A == 0x01) {
                state = INCREMENT;
            }
            else if (tmp_A == 0x02) {
                state = DECREMENT;
            }
            else if (tmp_A == 0x03) {
                state = RESET;
            }
            else {
                state = WAIT;
            }
            break;
        case INCREMENT:
            state = INC_PRESS;
            break;
        case DECREMENT:
            state = DEC_PRESS;
            break;
        case RESET:
            state = RES_PRESS;
            break;
        case INC_PRESS:
            if (tmp_A == 0x00) {
                state = WAIT;
            }
	    else if (tmp_A == 0x02) {
                state = DECREMENT;
	    }
	    else if (tmp_A == 0x03) {
                state = RESET;
            }
            else {
                state = INC_PRESS;
            }
            break;
	case DEC_PRESS:
            if (tmp_A == 0x00) {
                state = WAIT;
            }
            else if (tmp_A == 0x01) {
                state = INCREMENT;
            }
            else if (tmp_A == 0x03) {
                state = RESET;
            }
            else {
                state = DEC_PRESS;
            }
            break;
	case RES_PRESS:
            if (tmp_A == 0x00) {
                state = WAIT;
            }
	    else if (tmp_A == 0x01) {
                state = INCREMENT;
            }
            else if (tmp_A == 0x02) {
                state = DECREMENT;
            }
            else if (tmp_A == 0x03) {
                state = RESET;
            }
            else {
                state = RES_PRESS;
            }
            break;
        default:
            break;
    }

    /* State actions */
    switch(state) {
        case START:
            PORTC = 0x07;
            break;
        case INCREMENT:
            if (PORTC < 9) {
                PORTC++;
            }
            break;
        case DECREMENT:
            if (PORTC > 0) {
                PORTC--;
            }
            break;
        case RESET:
            PORTC = 0x00;
            break;
        case INC_PRESS:
	    break;
        case DEC_PRESS:
            break;
	case RES_PRESS:
            break;
	case WAIT:
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
