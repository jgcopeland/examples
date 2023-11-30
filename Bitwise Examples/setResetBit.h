#include <iostream>
using namespace std;

//sets the bit (=1) at the provided position (0-7) in the provided 8 bit integer
int setBit(uint8_t num, int bitPos) {
    num |= 0b1<<bitPos;
    return num;
}

//resets the bit (=0) at the provided position (0-7) in the provided 8 bit integer
int resetBit(uint8_t num, int bitPos) {
    num &= ~(0b1<<bitPos);
    return num;
}