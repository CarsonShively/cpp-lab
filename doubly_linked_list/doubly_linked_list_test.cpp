/**
 * general c++ later
 */

#include "doubly_linked_list.h"
#include <iostream>
#include <string>

void assert(int value, int index, const DoublyLinkedList& ll) {

    std::cout << "index: " << index << " value: " << value << "\n";
    ll.show();
}

void test() {
    // heap array for auto tests
    DoublyLinkedList ll;

    int indexes[] = {0, 1, 2, 3, 4, 5, 0, 0, 7, 8, 4, 3, 6};
    int values[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26};

    for (int i=0; i<13; i++) {
        ll.insert(values[i], indexes[i]);
        assert(values[i], indexes[i], ll);
    }

}

int main() {
    test();
    return 0;
}