#include <iostream>
#include "binFunctions.h"

using namespace std;

//swaps a given number of bits from a given starting positions in two provided numbers
//positions given 0-7 with 0 being the LSB, and num includes starting bit and goes up in significance. Pos 4, Num 3 = _ b6 b5 b4 _ _ _ _
//swaps the bits in the orginal memory location, does not return values.
void swapBits(uint8_t &num1, uint8_t &num2, int bitPos, int bitNum) {
    for(int i=bitPos; i<bitPos+bitNum; i++) {
        //if bit are different, then swap. If the same nothing needs to be done.
        if((num1 & 0b1<<i)>>i == 0b1) { //if num1 bit is '1'
            if((num2 & 0b1<<i)>>i == 0b0) { //if num2 bit is '0'
                num1 &= ~(0b1<<i); //reset  1 -> 0
                num2 |= 0b1<<i; //set  0 -> 1
            }
        }
        else { //if num1 bit is '0'
            if((num2 & 0b1<<i)>>i == 0b1) { //if num2 bit is '1'
                num1 |= 0b1<<i; //set  0 -> 1
                num2 &= ~(0b1<<i); //reset  1 -> 0
            }
        }
    }

    //xor swap:   https://en.wikipedia.org/wiki/XOR_swap_algorithm

}