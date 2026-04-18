/**
 * general c++ later
 * 
 * manual test
 * 
 * figure out auto tests in its own segment
 */

#include "doubly_linked_list.h"
#include <iostream>
#include <string>


void test() {
    DoublyLinkedList ll;

    for (int i=0; i<5; i++) {
        ll.insert(i+2, i);
    }

    ll.show();

    ll.remove(2);
    ll.show();
}

int main() {
    test();
    return 0;
}