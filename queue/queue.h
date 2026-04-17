/**
 * fifo
 * enqueue = add to back
 * dequeue = remove from front
 */
#include <string>

#ifndef QUEUE_H
#define QUEUE_H



class Queue{
    struct Node {
        long value; // 8 bytes lp64 + g++
        Node* next;
    };

    Node* head;
    int size;
public:
    Queue();
    ~Queue();
    void enqueue(long value);
    long dequeue();
};

#endif