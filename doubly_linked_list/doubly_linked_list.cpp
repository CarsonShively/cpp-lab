#include "doubly_linked_list.h"
#include <stdexcept>
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    size = 0;
}

void DoublyLinkedList::insert(int value, int index) {
    if (index < 0 || index > size) {
        throw std::out_of_range("out of range");
    }

    Node* insert = new Node{value, nullptr, nullptr};

    if (size == 0) {
        head = insert;
        size++;
    } else if (index == size) {
        Node* current = head;
        for (int i=0; i<size-1; i++) {
            current = current->next;
        }
        current->next = insert;
        insert->prev = current;
        size++;
    } else if (size != 0 && index == 0) {
        insert->next = head;
        head = insert;
        head->next->prev = head;
        size++;
    } else {
        Node* current = head;
        for (int i=0; i<index-1; i++) {
            current = current->next;
        }
        insert->next = current->next;
        insert->prev = current;
        current->next->prev = insert;
        current->next = insert;
        size++;
    }
}

int DoublyLinkedList::get(int index) const {
    Node* current = head;
    for (int i=0; i<index; i++) {
        current = current->next;
    }
    return current->value;
}

void DoublyLinkedList::show() const {
    std::cout << "show: ";
    Node* current = head;
    for (int i=0; i<size-1; i++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << current->value << "\n";
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    Node* next;
    for (int i = 0; i<size-1; i++) {
        next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::show_reverse() const {
    std::cout << "show reverse: ";
    Node* current = head;
    for (int i=0; i<size-1; i++) {
        current = current->next;
    }
    for (int i=0; i<size-1; i++) {
        std::cout << current->value << " ";
        current = current->prev;
    }
    std::cout << current->value << "\n";
}

void DoublyLinkedList::remove(int index) {
    if (size == 0 || index < 0 || index >= size) {
        return;
    } else if (index == 0) {
        Node* del = head;
        head = head->next;
        head->prev = nullptr;
        delete del;
        size--;
    } else if (index == size-1) {
        Node* current = head;
        for (int i=0; i<size-2; i++) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        size--;
    } else {
        Node* current = head;
        for (int i=0; i<index-1; i++) {
            current = current->next;
        }
        Node* del = current->next;
        current->next = current->next->next;
        current->next->prev = current;
        delete del;
        size--;
    }
}

void DoublyLinkedList::reverse() {
    Node* current = head;
    current->prev = current->next;
    current->next = nullptr;
    Node* tmp;
    for (int i=0; i<size-1; i++) {
        current = current->prev;
        tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
    }
    head = current;
}