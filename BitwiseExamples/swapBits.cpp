#include <iostream>
#include <math.h>

using namespace std;

//swaps consecutive bits from two sections of the  same integer
//xor swap ref:   https://en.wikipedia.org/wiki/XOR_swap_algorithm
//additional ref: https://www.geeksforgeeks.org/how-to-swap-two-bits-in-a-given-integer/
int swapBits(int num, int bitPos1, int bitPos2, int bitNum) {
    //isolates the bits to be swapped
    int bits1 = (num >> bitPos1) & int(pow(2,bitNum)-1); //ex: bitNum = 4 -> (2^4)-1 = 15 -> & 1111
    int bits2 = (num >> bitPos2) & int(pow(2,bitNum)-1);

    int x = bits1 ^ bits2; //XORs the bits with each other
    x = (x << bitPos1) | (x << bitPos2); // moves XOR's bits back to the original positions

    return num^x; //XORs the original number with the new bits in the shifted (to be swapped) positions
}

//swaps a given number of bits from a given starting positions in two provided numbers
//positions given with 0 being the LSB, and num includes starting bit and goes up in significance. Pos 4, Num 3 =... _ b6 b5 b4 _ _ _ _
//swaps the bits in the orginal memory location, does not return values.
void swapBitsTwoNum(int &num1, int &num2, int bitPos, int bitNum) {
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
}