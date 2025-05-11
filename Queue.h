/*
Header file that defines the Queue class using linked list.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Queue {
    
    // Structure for a queue node
    struct QueueNode {
        char value;
        QueueNode* next;
        QueueNode(char value1, QueueNode *next1 = nullptr) {
            value = value1;
            next = next1;
        }
    };

    // front: position where elements are removed 
    QueueNode* front;

    // rear: position where elements are added 
    QueueNode* rear;

    // count: keeps track of the number of elements in queue
    int count;

public:
    // Constructor to initialize the queue to empty
    Queue();

    // Destructor to free memory
    ~Queue();

    // enqueue: adds an element to the rear of the queue
    void enqueue(char);

    // dequeue: removes an element from the front of the queue
    void dequeue(char&);

    /* isEmpty: check to see if the queue is empty,
       Returns true if empty, false otherwise */
    bool isEmpty() const;

    /* isFull: check to see if the queue is full,
       Return true if full, false otherwise */
    bool isFull() const;

    // Function clear dequeues all the elements in the queue
    void clear();
};

#endif

