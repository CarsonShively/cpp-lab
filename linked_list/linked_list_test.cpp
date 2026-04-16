#include "linked_list.h"
#include <iostream>
#include <string>

// string is an object so dont copy pass it by address, dont edit what is at that address
int assert(char expected_output, char output, const std::string& test) {
    if (expected_output == output) {
        // chars are just 8 bit binary so you can compare directly
        std::cout << "PASS: " << test << "\n";
        return 1;
    } else {
        std::cout << "FAIL: " << test << "\n";
        return 0;
    }
}

void test_insert() {
    int pass = 0;
    std::cout << "=========== Insert Test ==============\n";
    LinkedList ll;
    ll.insert(0, 'c');
    pass += assert('c', ll.get(0), "first in linked list");
    ll.insert(1, 'a');
    pass += assert('a', ll.get(1), "second in linked list");
    ll.insert(1, 't');
    pass += assert('t', ll.get(1), "insert middle");
    std::cout << "Tests Passed: " << pass << "/3\n";
}

int main() {
    test_insert();
    return 0;
}