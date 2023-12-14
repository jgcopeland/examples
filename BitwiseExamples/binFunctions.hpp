#include <vector>
#ifndef BINFUNC_H
#define BINFUNC_H

//countBinOnes
int countBinOnes(int num);

//setResetBit
int setBit(int num, int bitPos);
int resetBit(int num, int bitPos);

//swapBits
int swapBits(int num, int bitPos1, int bitPos2, int bitNum);
void swapBitsTwoNum(int &num1, int &num2, int bitPos, int bitNum);

#endif