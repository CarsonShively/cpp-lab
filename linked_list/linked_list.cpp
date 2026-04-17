/**
 * how do compilers optimise memory?
 * 
 * low level c++ -> optimisation -> move lower then c++
 * 
 * learn concepts: overflow, sings, vector
 * 
 * look up concepts but implement them myself
 * 
 * main keys:
 *      pointer to the object acts as the object its pointing to using ->
 * 
 * lesser keys:
 *      setting pointers equal to pointers
 *      pointers in stack point to objects in heap
 */

#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() {
    size = 0;
    head = nullptr; // no first node to point to 
}

void LinkedList::insert(int index, char value) {
    if (index > size || index < 0) {
        return;
    }

    // stack frame makes it so you dont need address of first byte + type (size) to find data
    // heap you need address of first byte + size which comes from type

    // "aggregate initialisation" when there is no constructor of a struct
    // "new" means allocate heap of size x
    // how many of that size is based off[] or no []
    // save the address of the first byte of a type Node
    Node* new_node = new Node{value, nullptr}; // order of members in struct
    // start with null ptr then update it if not last

    if (size == 0) {
        head = new_node;
        size++;
    } else if (index == size) {
        Node* current = head;

        for (int i=0; i<size-1; i++) {
            current = current->next;
        }

        current->next = new_node;
        size++;

    } else if (index == 0) {
        new_node->next = head; // a pointer to an object represents that object, head represents the first object
        head = new_node; //change the object head represents to the object that new node represents
        size++;
    } else {
        Node* current = head; // pointing to the same object as head

        for (int i=0; i<index-1; i++) {
            current = current->next; // 2 before the index then next to get 1 before
        }

        new_node->next = current->next;
        current->next = new_node;
        size++;
    }
}

// when setting equal to an address with no & you are going to that address
// your pointing to the whole type starting at that byte address
char LinkedList::get(int index) const {
    if (index >= size || index < 0) {
        return '\0';
    }


    // a pointer to an object esentially is that object using ->
    // head is a pointer to the first object
    // head essentially is the first object 
    // node is an object
    Node* current = head;
    for (int i=0; i<index; i++) {
        current = current->next;
    }

    // segfault came from skipping first node which was the one needed

    return current->value;
}

// head next is a pointer to a node object
// when stack object goes out of scope destructor is called automatically 
LinkedList::~LinkedList() {
    Node* current = head; //current is on stack holding a pointer to heap
    Node* next;
    for (int i=0; i<size; i++) {
        next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        std::cout << "debug" << std::endl;
        return;
    }

    if (index == 0) {
        head = head->next;
        size--;
    } else if(index == size-1) {
        Node* current = head;
        //if index 0 is set outside the loop, <index gets 
        for (int i=0; i<size-2; i++) {
            current = current->next;
        }
        current = nullptr;
        size--;

    } else {
        Node* current = head;
        // checks condition at beginning, incrememnts at end
        // runs once for each i that is less than condition
        // count how many times it would run
        // what is the last number it will run for
        // flow = check condition -> body -> increment
        // runs the number od times of <x
        // would running it once put you at the first or second index
        // get to an index <index
        // get last size-1
        // offset from index, index+-

        // index 0 outside loop = size-1 == last, use this to get index
        for (int i = 0; i<index-1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        size--;
    }



}

void LinkedList::show() const {
    Node* current = head;
    for(int i=0; i<size; i++) {
        std::cout << current->value; // when you accessing through a pointer, not accessing a pointer field
        current = current->next;
    }
    std::cout << "\n";
    // malloc == built in == hides lower levels == not what i want
}

int LinkedList::get_size() const {
    return size;
}