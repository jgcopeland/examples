#include <iostream>
#include <vector>
#include "binFunctions.hpp"

using namespace std;

//File used as main.cpp to call all binary example functions

//How to do correctly? use header file? use extern somehow?

int main() {

// countBinOnes()
//------------------------------------------------------------------------------------
    int num8 = 0x56; //Is hex the standard format to use for embedded applications? Or are there cases where you use bin/oct?
    cout << num8 << " has " << countBinOnes(num8) << " binary ones.\n";

    num8 = 0x1;
    cout << num8 << " has " << countBinOnes(num8) << " binary one.\n";

    num8 = 0xBF;
    cout << num8 << " has " << countBinOnes(num8) << " binary ones.\n";

    num8 = 0xD;
    cout << num8 << " has " << countBinOnes(num8) << " binary ones.\n";

    cout << "\n";

    num8 = 256;
    cout << num8 << " has " << countBinOnes(num8) << " binary ones.\n";

    num8 = 65535;
    cout << num8 << " has " << countBinOnes(num8) << " binary ones.\n";

    num8 = 12359;
    cout << num8 << " has " << countBinOnes(num8) << " binary ones.\n";

    num8 = 984;
    cout << num8 << " has " << countBinOnes(num8) << " binary ones.\n\n\n";

// setResetBit()
//------------------------------------------------------------------------------------
    num8 = 0x56;
    int bit = 0;
    cout << num8 << " had bit " << bit << " set. It is now " << setBit(num8, bit) << ".\n";

    num8 = 0x57;
    bit = 0;
    cout << num8 << " had bit " << bit << " reset. It is now " << resetBit(num8, bit) << ".\n";

    num8 = 0xBF;
    bit = 6;
    cout << num8 << " had bit " << bit << " set. It is now " << setBit(num8, bit) << ".\n";

    num8 = 0xBF;
    bit = 5;
    cout << num8 << " had bit " << bit << " reset. It is now " << resetBit(num8, bit) << ".\n\n\n";

// swapBitsTwoNum()
//------------------------------------------------------------------------------------
    int num1 = 0x9C; //156
    int num2 = 0x72; //114
    cout<<"Num1: " << num1 << "\nNum2: " << num2 << "\n";
    swapBitsTwoNum(num1, num2, 4, 3);
    cout<<"Num1: " << num1 << "\nNum2: " << num2 << "\n";

    num1 = 0x01; //1
    num2 = 0x72; //114
    cout<<"Num1: " << num1 << "\nNum2: " << num2 << "\n";
    swapBitsTwoNum(num1, num2, 0, 1);
    cout<<"Num1: " << num1 << "\nNum2: " << num2 << "\n\n";

// swapBits()
//------------------------------------------------------------------------------------
    num1 = 0x72; // 114
    int pos1 = 4;
    int pos2 = 7;
    int bitNum = 1;
    cout << num1 << " had " << bitNum <<" bit from positions " << pos1 << " and " << pos2 << " swapped. Now it is " << swapBits(num1, pos1, pos2, bitNum) << ".\n";
    // [0] 1 1 [1] 0 0 1 0 -> [1] 1 1 [0] 0 0 1 0 = 114 -> 226

    num1 = 0x9C; // 156
    pos1 = 1;
    pos2 = 5;
    bitNum = 2;
    cout << num1 << " had " << bitNum <<" bits from positions " << pos1 << " and " << pos2 << " swapped. Now it is " << swapBits(num1, pos1, pos2, bitNum) << ".\n";
    // 1 [0 0] 1 1 [1 0] 0 -> 1 [1 0] 1 1 [0 0] 0 = 156 -> 216

    num1 = 0xD576; // 54,646
    pos1 = 3;
    pos2 = 8;
    bitNum = 4;
    cout << num1 << " had " << bitNum <<" bit from positions " << pos1 << " and " << pos2 << " swapped. Now it is " << swapBits(num1, pos1, pos2, bitNum) << ".\n";
    // 1 1 0 1 [0 1 0 1] 0 [1 1 1 0] 1 1 0 -> 1 1 0 1 [1 1 1 0] 0 [0 1 0 1] 1 1 0 = 54,646 -> 56,878

    return 0;
}