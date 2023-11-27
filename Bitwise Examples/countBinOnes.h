#include <iostream>
#include <math.h>
using namespace std;

int countBinOnes(uint8_t num) {
    int numOnes = 0;
    // for(int i = 7; i >= 0; i--) {
    //     if(num % int(pow(2,i)) < num) {
    //         num -= pow(2,i);
    //         numOnes++;
    //     }
    // }
    // return numOnes;

    for(int i = 7; i >= 0; i--) {
        if((num & 0b1<<i)>>i == 0b1) {
            numOnes++;
        }
    }
    return numOnes;
}

int countBinOnes(uint16_t num) {
    int numOnes = 0;
    for(int i = 15; i >= 0; i--) {
        if(num % int(pow(2,i)) < num) {
            num -= pow(2,i);
            numOnes++;
        }
    }
    return numOnes;
}