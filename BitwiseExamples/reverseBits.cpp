#include <math.h>
#include <iostream>
using namespace std;

// Reverse bits of a given 32 bits unsigned integer.

// Note:
// Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

// Example 1:
// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.


// Example 2:
// Input: n = 11111111111111111111111111111101
// Output:   3221225471 (10111111111111111111111111111111)
// Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

// Constraints:
// The input must be a binary string of length 32

// Follow up: If this function is called many times, how would you optimize it?

int reverseBits(int num) {
    //repeatedly swap pairs of bits at opposite sides of number
    int halfSize = int((log2(num)+1)/2);
    for(int i = log2(num), j=0 ; i>=halfSize; i--, j++) { //iterates in both directions towards middle
        //isolates the bits to be swapped
        int bits1 = (num >> i) & 1;
        int bits2 = (num >> j) & 1;

        int x = bits1 ^ bits2; //XORs the bits with eachother
        x = (x << i) | (x << j); // moves XOR's bits back to the original positions
        num ^= x; //XORS with new bits to produce new number with switched bits
        //cout << "\ni: " << i << " j: " << j << " num: " << num; //debug
    }
    
    return num;
}
