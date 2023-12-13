#include <iostream>

using namespace std;

//sets the bit (=1) at the provided position in the provided 8 bit integer
int setBit(int num, int bitPos) {
    //takes 8 bit num [ b7 b6 b5 b4 b3 b2 b1 b0 ] and sets the bit to "1" by ORing with a shifted 0b1. Ex, bitPos = 4 [ 0 0 0 1 0 0 0 0]
    // Ex: [ b7 b6 b5 b4 b3 b2 b1 b0 ]
    //  OR [  0  0  0  1  0  0  0  0 ]
    //   = [ b7 b6 b5  1 b3 b2 b1 b0 ]
    num |= 0b1<<bitPos; 
    return num;
}

//resets the bit (=0) at the provided position in the provided 8 bit integer
int resetBit(int num, int bitPos) {
    //takes 8 bit num [ b7 b6 b5 b4 b3 b2 b1 b0 ] and sets the bit to "0" by ANDing with the inverse of a shifted 0b1. Ex, bitPos = 4 [ 1 1 1 0 1 1 1 1]
    // Ex: [ b7 b6 b5 b4 b3 b2 b1 b0 ]
    // AND [  1  1  1  0  1  1  1  1 ]     -->   ~[ 0 0 0 1 0 0 0 0 ] = [ 1 1 1 0 1 1 1 1 ]
    //   = [ b7 b6 b5  0 b3 b2 b1 b0 ]
    num &= ~(0b1<<bitPos);
    return num;
}