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
        front = -1; //index of front element
        rear = 0; //index of rear element (always 0, included just for reference)
        maxSize = size; //max size of array
        arr = new int[size]; //create queue array
    }

    //inserts an element at the back of the queue (back of queue = start of array)
    void enqueue(int num) {
        //check if queue is full
        if(isFull()) {
            cout<<"Cannot enqueue element: Queue is Full.\n";
            return;
        }

        front++; //increment front index

        //shift every element to the right by 1 index
        for(int i = front; i >= rear; i--) {
            arr[i+1] = arr[i];
        }

        //insert new element at rear
        arr[rear] = num; 
        cout << num << " was added to the queue.\n"; //debug
    }

    //removes the element at the front of the queue
    int dequeue() {
        //decrement front
        int num = 0;
        return num;
    }

    //returns item at front of queue without dequeueing
    int getFront() {
        return arr[front];
    }

    //returns item at rear of queue without dequeueing
    int getRear() {
        return arr[rear];
    }

    //checks if the queue contains any elements
    bool isEmpty() {
        if(front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    //checks if the queue can hold any more elements
    bool isFull() {
        if(front == maxSize-1) {
            return true;
        }
        else {
            return false;
        }
    }

    //prints queue to terminal for debugging/visualization purposes
    void printQueue(bool showAll) {
        if(isEmpty()){
            cout << "Cannot print queue: Queue is Empty\n";
        }
        else {
            if(showAll) { //debug
                for(int i = 0; i < maxSize; i++) { //prints entire array in index order
                    cout << arr[i] << " | ";
                }
            }
            else {
                for(int i = front; i >= rear; i--) { //prints queue with front on left and rear on right
                    cout << arr[i] << " | ";
                }
            }
        }
        cout << "\n";
    }
};

int main() {
    Queue myQueue = Queue(5);

    myQueue.enqueue(1);
    myQueue.printQueue(false);

    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.printQueue(false);

    myQueue.enqueue(5);
    myQueue.printQueue(false);
    myQueue.enqueue(6);
    myQueue.printQueue(false);

    return 0;
}