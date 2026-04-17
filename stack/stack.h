/**
 * LIFO
 * dynamic array
 * back == in out
 */
#ifndef STACK_H
#define STACK_H

class Stack {
    // linked list uses pointers that represent/act as objects
// array uses offsets of types
public:

    struct Thread { // not ordered
        int start;
        int end;
    };
    
    Stack();
    ~Stack();
    void push(int start, int end);
    Thread pop();
    void resize();

    // private struct is really only good for linked list becuase it cant be used as a type whcih loses the point of structuing data
    int size;
    int capacity;
    Thread* data;
};


#endif