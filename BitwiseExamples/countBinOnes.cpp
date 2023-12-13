#include <iostream>
#include <math.h>

using namespace std;

//Counts the number of binary 1s in a given integer of any length
int countBinOnes(int num) {
    //return __builtin_popcount(num); //built in function to count 1s
    //...

    // Algebraic
    // int numOnes = 0;
    // for(int i = 7; i >= 0; i--) {
    //     if(num % int(pow(2,i)) < num) {
    //         num -= pow(2,i);
    //         numOnes++;
    //     }
    // }
    // return numOnes;

    //Bitwise approach for 32 bit int
    //https://web.archive.org/web/20151229003112/http://blogs.msdn.com/b/jeuge/archive/2005/06/08/hakmem-bit-count.aspx

    //Bitwise - couldn't see way to do without looping
    int numOnes = 0; //initialize counter to 0
    for(int i = log2(num)+1; i >= 0; i--) { //loop through each position in the binary number, log2(num)+1 = binary length of num
        //num & 0b1<<i  -  Ands the 8bit integer with a binary one that is left shifted i times (for loop will perform this for each binary position)
        //(..)>>i == 0b1  -  right shifts the result i times to compare to a binary 1. If equal to 1, that means that the num bit at i is equal to a 1.
        if((num & 0b1<<i)>>i == 0b1) { 
            numOnes++; //increment the counter if a one is found
        }
    }
    return numOnes; //return total of counter
}

// //Counts the number of binary 1s in a given 8 bit integer
// int countBinOnes(uint8_t num) {
//     // int numOnes = 0;
//     // for(int i = 7; i >= 0; i--) {
//     //     if(num % int(pow(2,i)) < num) {
//     //         num -= pow(2,i);
//     //         numOnes++;
//     //     }
//     // }
//     // return numOnes;

//     int numOnes = 0; //initialize counter to 0
//     for(int i = 7; i >= 0; i--) { //loop through each position in the binary number (8->0)
//         //num & 0b1<<i  -  Ands the 8bit integer with a binary one that is left shifted i times (for loop will perform this for each binary position)
//         //(..)>>i == 0b1  -  right shifts the result i times to compare to a binary 1. If equal to 1, that means that the num bit at i is equal to a 1.
//         if((num & 0b1<<i)>>i == 0b1) { 
//             numOnes++; //increment the counter if a one is found
//         }
//     }
//     return numOnes; //return total of counter
// }

// //Counts the number of binary 1s in a given 16 bit integer
// int countBinOnes(uint16_t num) {
//     // int numOnes = 0;
//     // for(int i = 15; i >= 0; i--) {
//     //     if(num % int(pow(2,i)) < num) {
//     //         num -= pow(2,i);
//     //         numOnes++;
//     //     }
//     // }
//     // return numOnes;

//     int numOnes = 0; //initialize counter to 0
//     for(int i = 15; i >= 0; i--) { //loop through each position in the binary number (15->0)
//         //num & 0b1<<i  -  Ands the 8bit integer with a binary one that is left shifted i times (for loop will perform this for each binary position)
//         //(..)>>i == 0b1  -  right shifts the result i times to compare to a binary 1. If equal to 1, that means that the num bit at i is equal to a 1.
//         if((num & 0b1<<i)>>i == 0b1) { 
//             numOnes++; //increment the counter if a one is found
//         }
//     }
//     return numOnes; //return total of counter
// }