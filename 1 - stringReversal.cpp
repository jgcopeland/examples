/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//this comment was changed and pushed from vscode to github  

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string reverseWord1(string word) {
    string revWord = "";  //initialize empty string for new word
    
    for(int i = word.length()-1;i >= 0;i--) { //start from the last character of the string and iterate until the first
        revWord += word[i]; //each iteration add the current character to the end of the new blank string
    }
    
    return revWord; //return reversed word
}

void reverseWord2(string* word) {
    char temp; //temp variable for character storage
    int strLength = word->length(); //get length of string
    int n = strLength-1; //initialize reverse iterator to start at last index
    
    for(int i = 0; i <= (strLength-1)/2; i++) { //start from the first character and iterate until the middle character
        temp = (*word)[i]; //save char at index i
        (*word)[i] = (*word)[n]; //swap char at index n to index i
        (*word)[n] = temp; //swap char from index i to index n
        
        n--; //decrement index to move one character towards the start of the string
    }

    //return word; //returns pointer to string - not needed
}

int main() {
//	string word;
//  cout << "Type a word to reverse: "; //prompt
//  cin >> word; // get input
    
    string word = "ABCDEFG HIJKLMNOP QRSTUV WXYZ"; //setting input word manually
    cout << "Starting word is: " + word + "\n";
    
    cout << "Here is the reversed string from F1:     " + reverseWord1(word) + "\n"; //call function1 + print to console
//  cout << word + "\n"; //still has original value after function1
    
    reverseWord2(&word); //function operates on original copy of string
    cout << "Here is the reversed string from F2:     " + word; //print to console after calling function2
   
  	return 0;
}

/*
Notes on Implementation:
References
https://github.com/openjdk-mirror/jdk7u-jdk/blob/master/src/share/classes/java/lang/AbstractStringBuilder.java
https://geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
https://stackoverflow.com/questions/2439141/what-is-the-most-efficient-algorithm-for-reversing-a-string-in-java
https://www.digitalocean.com/community/tutorials/reverse-string-c-plus-plus

Disadvantage
	More of a brute force approach, it does every character one at a time.
	As a result, if a string is n characters long, the loop will run n times.
Better Solution																						
	One way to cut down on the nuber of times the loop must run would be to iterate from both sides.
	Then, you can swap the characters on both ends with each other until the middle is reached.
	With this, if a string is n characters long it will run ~n/2 times.
Questions
    Would this actually make the program execute faster? Or will it just be doing more in the loop every time it runs,
    making each loop take longer?
	
Disadvantage
	If used on a long string, a whole new string is created and stored on the stack while the function executes.
	This may use more memory to run than other implementations.
Better Solution
	You can pass the reversal function a pointer to the original string and perform modifications directly to the string.
	(Assuming that the original string is no longer needed to access directly)
	By changing the value at the location of the string instead, it does not need to use stack memory to store a new string 
	while it is executing. It can simply allocate stack memory for the temporary character and iterators, etc. needed.
Questions
    Would doing this make accesses substantially slower from the direct reference for each character? Or is it the same because 
    it is just referencing a different address from the stack?
	
	Pointers will inherently take additional time to obtain the value that is stored.
	For pointers, you
		1) look up the address of the pointer
		2) get the value a that address (this is the address of the value its pointing to)
		3) get the value at the address obtained from the pointer
		
	For varibales though, you can stop at two as you will have the desired value already.
	It is not a large/signifcant amount of time, but it will be additional steps to access via pointers.
*/
