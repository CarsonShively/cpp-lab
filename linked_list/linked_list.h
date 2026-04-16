/**
 * constraints:
 * - lp64 abi
 * - stop at vm
 * - stop at machine code / compiler
 * - lowest level c++
 * - g++ compiler
 * 
 * notes:
 * when you allocate a block of heap that block's addresses are in order
 * when you allocate 1 at a time the addresses are not in order
 * 
 * this is the reason you have to allocate a larger block and copy instead of resizing the current one
 * you cant allocate memory that follows what you already have allocated
 * 
 * the differende between linked list and array is that they are not in order
 * 
 * objects get 7 bytes of padding for this build configureation
 * build config = abi + compiler
 */

// members default to public, simpler but not encapsulated
// the ONLY difference between struct and class is member defaults, allow for all same options
#ifndef LINKED_LIST_H // variable not an include
#define LINKED_LIST_H

// classes are not memory, objects are
// classes and strucs are not public private by default theri members are
class LinkedList {

    // the only place that can create a node object is in teh linked list
    // seperate objects in seperate memory locations
    struct Node {
        char value;
        Node* next; // pointing to the next node object, not just the char value in the node
        // hold pointer in object in stack to an address in heap
    };

    // maintain instantiated linked list object's state
    Node* head; // how the linked list object finds the first node object
    int size;

public:
    LinkedList();
    ~LinkedList();
    void insert(int index, char value);
    /* void remove(int index); */
    char get(int index) const; // cant change members
    /* void replace(char value, int index); */


};

#endif