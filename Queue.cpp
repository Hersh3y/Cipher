/*
This is the implementation file for the Queue class.
It implements a dynamic queue using linked list.
*/

#include "Queue.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Constructor to initialize the queue to empty
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
}

// Destructor to free memory
Queue::~Queue() {
    QueueNode * garbage = front;
    while (garbage != nullptr) {
        front = front->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = front;
    }
}

// enqueue: adds an element to the rear of the queue 
void Queue::enqueue(char a) {
    if (isFull()) {
        cout << "The queue is full.\n";
        return;
    }
    
    if (isEmpty()) {
        front = new QueueNode(a);
        rear = front;
    } 
    else {
        rear->next = new QueueNode(a);
        rear = rear->next;
    }
    
    count++;
}

// dequeue: removes an element from the front of the queue
void Queue::dequeue(char &value) {
    
    QueueNode *temp = nullptr;
    
    if (isEmpty()) {
        cout << "The queue is empty.\n";
        exit(1);
    } 
    else {
        value = front->value;
        temp = front;
        front = front->next;
        delete temp;
        count--;
    }
}

/* isEmpty: check to see if the queue is empty,
   Returns true if empty, false otherwise */
bool Queue::isEmpty() const {
    return front == nullptr;
}

/*  isFull: check to see if the queue is full,
    Return true if full, false otherwise */
bool Queue::isFull() const {
    return count >= 100;
}

// Function clear dequeues all the elements in the queue
void Queue::clear() {
    char value;
    while (!isEmpty()) {
        dequeue(value);
    }
}
