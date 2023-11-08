/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/
//saw implementation used class, so went with that approach but coded everything on my own

#include <iostream>

using namespace std;
class Stack {
    int top;
    int maxSize;
    int* arr; //pointer so can set size of array when creating
    
    public:
    //Constructor
    Stack(int size) {
        top = -1; //index of top element
        maxSize = size; //max size or array
        arr = new int[size]; //create stack array
    }
    
    //adds item to the top of the stack
    void push(int num) {
        if(isFull()) {
            cout << "Cannot add to stack: Stack Full\n";
        }
        else {
            top++; //increment top index
            arr[top] = num; //add to stack
        }
    }
    
    //removes item from the top of the stack and returns the value that was removed
    int pop() {
        if(isEmpty()) {
            cout << "Cannot remove from stack: Stack Empty\n";
            return -99;
        }
        else{
            int temp = arr[top]; //save value at current top index
            top--; //decrement top index
            return(temp); //return element at original top index
        }
    }
    
    //returns value on top of the stack without popping it off the stack
    int getTop() {
        if(isEmpty()) {
            cout << "Cannot remove from stack: Stack Empty\n";
            return -99;
        }
        else{
            return(arr[top]);            
        }

    }
    
    //checks if the top index is equal to -1 (no value at first index)
    //if so, the stack is empty
    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    
    //checks if top index is equal to the max size-1 (equal to the final index given by the specified size)
    //if so, the stack is full
    bool isFull() {
        if(top == maxSize-1) {
            return true;
        }
        else {
            return false;
        }
    }
    
    //returns number of elements in stack array
    int size() {
        return top+1; //number of elements will be one greater than the top index 
    }
    
    void printStack() {
        if(isEmpty()){
            cout << "Cannot print stack: Stack Empty\n";
        }
        else {
            for(int i = 0; i <= top; i++) {
                cout << arr[i];
                cout << " | ";
            }
            
        }
        cout << "\n";
    }

};


int main()
{
    class Stack myStack = Stack(5);
    myStack.push(1);
    myStack.printStack();

    myStack.push(8);
    myStack.printStack();

    myStack.push(5);
    myStack.printStack();

    myStack.push(9);
    myStack.printStack();

    myStack.push(42);
    myStack.printStack();
    
    cout<< myStack.pop();
    cout<< "\n";
    myStack.printStack();
    
    cout<< myStack.size();
    cout<< "\n";
    myStack.printStack();
    
    cout<< myStack.getTop();
    cout << "\n";
    myStack.printStack();
    
    myStack.push(23);
    myStack.printStack();
    
    myStack.push(39);
    myStack.printStack();
    
    myStack.push(98);
    myStack.printStack();
    
    myStack.push(12);
    myStack.printStack();
    
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.printStack();
    myStack.pop();
    myStack.printStack();
    
    myStack.pop();
    
    return 0;
}
