#include <iostream>

using namespace std;

class Node {
    public:
        int val; //data stored in node
        Node* next; //pointer to next node in linked list
        
        //constructor
        Node(int num) {
            val = num; //set value stored by node
            next = nullptr; //points to null since no next node yet
        }
};

class Stack {
    public:
            
        Node* top; //pointer to top of stack
        int maxSize; //artificially limit max size (no real limit like with an array)
        int size; //current size of stack
        
        //constructor
        Stack(int sizeLimit) {
            top = nullptr; //initialize top to nullptr
            maxSize = sizeLimit; //set maxSize to value passed
            size = 0; //size will start at 0 because the stack starts empty
        }
        
        //adds node to top of stack (beginning of linked list)
        void push(int num) {
            if(isFull()) {
                cout << "Cannot push to stack: Stack is at maximum size.\n";
            }
            else {
                Node* newNode = new Node(num); //create pointer to new node
                newNode->next = top; //set next pointer of new node to point to node currently at the top of the stack
                top = newNode; //update top pointer to the new node that was placed at the start
                
                size++; //increment to track stack size
                cout << newNode->val << " was added to the stack.\n"; //debug
            }
        }
        
        //removes node from top of stack (beginning of linked list)
        int pop() {
            if(isEmpty()) {
                cout << "Cannot pop form stack: Stack is empty.\n";
                return -99;
            }
            else {
                int temp = top->val; //save value of current top of stack
                top = top->next; //update top pointer to remove reference to previous top of stack
                size--; //decrement to track stack size
                
                cout << temp << " was removed from the stack.\n"; //debug
                return temp;
            }
        }
        
        //returns value of node at top of stack without removing it
        int getTop() {
            if(isEmpty()) {
                cout << "Cannot get top element: Stack is empty.\n";
                return -99;
            }
            return top->val;
        }
        
        //checks if the stack is empty
        bool isEmpty() {
            if(size == 0) {
                return true;
            }
            
            return false;
        }
        
        //checks if the stack is full
        bool isFull() {
            if(size == maxSize) {
                return true;
            }
            
            return false;
        }
        
        //gets the current size of the stack
        int getSize() {
            return size;   
        }
        
        //prints the current stack contents in console
        void printStack() {
            Node* curr = top; //set current node to top of stack
            
            while(curr != nullptr) {
                cout << curr->val << " | ";
                curr = curr->next;
            }
            cout<< "\n";
        }
};

int main()
{
    class Stack myStack = Stack(5);
    myStack.push(10);
    myStack.printStack();
    myStack.push(11);
    myStack.printStack();
    myStack.push(12);
    myStack.printStack();
    myStack.push(13);
    myStack.printStack();
    myStack.push(14);
    myStack.printStack();
    myStack.push(15);
    myStack.printStack();
    cout<<"TOP:"<<myStack.getTop()<<"\n";
    cout<<"SIZE:"<<myStack.getSize()<<"\n";
    
    myStack.pop();
    myStack.printStack();
    myStack.pop();
    myStack.printStack();
    cout<<"TOP:"<<myStack.getTop()<<"\n";
    cout<<"SIZE:"<<myStack.getSize()<<"\n";
    
    return 0;
}