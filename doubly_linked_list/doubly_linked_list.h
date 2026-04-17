#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

class DoublyLinkedList {
    struct Node {
        int value; // bool makes it a 50/50 of being right even when logic is wrong
        Node* prev;
        Node* next;
    };
    Node* head;
    int size;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(int value, int index);
    int get(int index) const;
    void show() const;
    void remove(int index);
    void show_reverse() const;
    void reverse();
    
};

#endif