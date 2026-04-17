#include "stack.h"
#include <iostream>
#include <string>
#include <stdexcept>

Stack::Stack() {
    size = 0;
    capacity = 0;
    data = nullptr;
}

Stack::~Stack() {
    delete[] data;
    // linked list needs to free on remove
    // array free block as end fo stack frame
}

void Stack::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Thread* new_data = new Thread[capacity];
    for (int i=0; i<size; i++) {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;

}

void Stack::push(int start, int end) {
    if (size == capacity) {
        resize();
    }
    data[size] = Thread{start, end};
    size++;
}

Stack::Thread Stack::pop() {
    if (size == 0) {
        throw std::out_of_range("Out of range");
    }
    //this gets the object &data for address/pointer
    Thread pop = data[size-1]; // copy the thread object to stack, not by address becuase the address could be overwritten after size-- push 
    // data[] is the object not the address, &data[] would be the address
    // address of thread object = adress of thread object (has to match) 
    // [offset from data not what is being returned]
    size--;
    return pop;
}