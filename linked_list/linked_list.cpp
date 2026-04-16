/**
 * how do compilers optimise memory?
 * 
 * c++ -> optimisation -> move lower
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
        new_node->next = head->next;
        head = new_node;
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