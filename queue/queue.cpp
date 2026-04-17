#include "queue.h"
#include <iostream>
#include <stdexcept>
/**
 * primitive data structures-> primitive sorting -> object data structures -> object sorting -> optimisation -> move lower
 * 
 * objects dilute the concept
 * 
 * always <
 * to index:
 *      index 0 outside:
 *          index
 *      index 0 inside:
 *          index+1     
 * 
 * to end:
 *      index 0 outside:
 *          size-1
 *      index 0 inside:
 *          size
 * 
 */

Queue::Queue() {
    head = nullptr;
    size = 0;
}

// Order* order would be the pointer
// dont make a copy on stack, use the actual object& pointer*
void Queue::enqueue(long value) {
    Node* enqueue = new Node{value, nullptr};

    if (size == 0) {
        head = enqueue;
        size++;
    } else {
        Node* current = head;
        
        // rule = is index 0 outside or inside loop
        // is first step of loop to index 1 or to index 0

        // <index == index when index 0 is outside the loop
        // this would mean index+1 when index 0 is inside loop

        // index 0 == set outside the loop use size-1
        // else use size

        for (int i=0; i<size-1; i++) {
            current = current->next;
        }
        current->next = enqueue;
        size++;
    }
}

long Queue::dequeue() {
    if(size == 0) {
        throw std::out_of_range("empty");
    }
    long value = head->value;
    Node* to_delete = head;
    head = head->next;
    delete to_delete;
    size--;
    return value;
}

Queue::~Queue() {
    Node* current = head;
    for (int i=0; i<size-1; i++) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}