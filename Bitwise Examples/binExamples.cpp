#include <iostream>
#include "countBinOnes.h"
#include "setResetBit.h"
using namespace std;

//File used as main.cpp to call all binary example functions

//How to do correctly? use header file? use extern somehow?

int main() {

// countBinOnes.h
//------------------------------------------------------------------------------------
    uint8_t num8 = 0x56; //Is hex the standard format to use for embedded applications? Or are there cases where you use bin/oct?
    cout << int(num8) << " has " << countBinOnes(num8) << " binary ones.\n";

    num8 = 0x1;
    cout << int(num8) << " has " << countBinOnes(num8) << " binary one.\n";

    num8 = 0xBF;
    cout << int(num8) << " has " << countBinOnes(num8) << " binary ones.\n";

    num8 = 0xD;
    cout << int(num8) << " has " << countBinOnes(num8) << " binary ones.\n";

    cout << "\n";

    uint16_t num16 = 256;
    cout << int(num16) << " has " << countBinOnes(num16) << " binary ones.\n";

    num16 = 65535;
    cout << int(num16) << " has " << countBinOnes(num16) << " binary ones.\n";

    num16 = 12359;
    cout << int(num16) << " has " << countBinOnes(num16) << " binary ones.\n";

    num16 = 984;
    cout << int(num16) << " has " << countBinOnes(num16) << " binary ones.\n\n\n";

// setResetBit.h
//------------------------------------------------------------------------------------
    num8 = 0x56;
    int bit = 0;
    cout << int(num8) << " had bit " << bit << " set. It is now " << setBit(num8, bit) << ".\n";

    num8 = 0x57;
    bit = 0;
    cout << int(num8) << " had bit " << bit << " reset. It is now " << resetBit(num8, bit) << ".\n";

    num8 = 0xBF;
    bit = 6;
    cout << int(num8) << " had bit " << bit << " set. It is now " << setBit(num8, bit) << ".\n";

    num8 = 0xBF;
    bit = 5;
    cout << int(num8) << " had bit " << bit << " reset. It is now " << resetBit(num8, bit) << ".\n";

    return 0;
}