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

    //Bitwise - couldn't see way to do without looping
    // int numOnes = 0; //initialize counter to 0
    // for(int i = log2(num); i >= 0; i--) { //loop through each position in the binary number, log2(num)+1 = binary length of num
    //     //num & 0b1<<i  -  Ands the 8bit integer with a binary one that is left shifted i times (for loop will perform this for each binary position)
    //     //(..)>>i == 0b1  -  right shifts the result i times to compare to a binary 1. If equal to 1, that means that the num bit at i is equal to a 1.
    //     if((num & 0b1<<i)>>i == 0b1) { 
    //         numOnes++; //increment the counter if a one is found
    //     }
    // }
    // return numOnes; //return total of counter

    // int numOnes = 0;
    // int size = log2(num)+1;
    // for(int i = 0; i<size; i++) {
    //     if(num & 0b1 == 0b1) {
    //         numOnes++;
    //     }
    //     num = num >> 1;
    // }
    // return numOnes;

    //Brain Kernighan's Algorithm - https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
    //the number of executions is equal to the number of ones
    //ex) 8
    //  1000 & 0111 = 0000 -> 1
    //
    //ex) 13
    //  1101 & 1100 = 1100
    //  1100 & 1011 = 1000
    //  1000 & 0111 = 0000 -> 3
    
    int numOnes = 0;
    while(num>0) {
        num &= (num-1);
        numOnes++;
    }
    return numOnes;

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