#include <iostream>

using namespace std;

class Queue {
    int front;
    int rear;
    int maxSize;
    int* arr; //pointer so can set size of array when creating

    public:
    //Constructor
    Queue(int size) {
        int front = 0; //index of front element
        int rear = 0; //index of rear element
        maxSize = size; //max size of array
        arr = new int[size]; //create queue array
    }

    //inserts an element at the back of the queue (back of queue = start of array)
    void enqueue(int num) {

    }

    //removes the element at the front of the queue
    int dequeue() {
        int num = 0;
        return num;
    }

    //returns item at front of queue without dequeueing
    int front() {

    }

    //returns item at rear of queue without dequeueing
    int rear() {

    }

    //checks if the queue contains any elements
    bool isEmpty() {

    }

    //checks if the queue can hold any more elements
    bool isFull() {

    }

    //prints queue to terminal for debugging/visualization purposes
    void printQueue() {

    }
};

int main() {


    return 0;
}