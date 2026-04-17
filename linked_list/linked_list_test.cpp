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

int test(const std::string& expected_output, int size, const LinkedList& ll) {
    
    // <size == 1 less than size
    // <index == the index
    for (int i=0; i<size; i++) {
        if(expected_output[i] != ll.get(i)) {
            std::cout << "=========== Fail ==========\n";
            std::cout << "Expected: " << expected_output << "\n" << "Actual: ";
            ll.show();
            return 0;
        }
    }
    std::cout << "========== Pass ==========\n";
    ll.show();
    return 1;
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

void test_delete() {
    int pass = 0;
    std::cout << "========== Test Delete ==============\n";
    LinkedList ll;
    ll.insert(0, 'C');
    ll.insert(1, 'a');
    ll.insert(2, 'r');
    ll.insert(3, 's');
    ll.insert(4, 'o');
    ll.insert(5, 'n');
    ll.remove(0);
    pass += assert('a', ll.get(0), "remove first");
    ll.show();
    std::cout << "\n";
    ll.insert(0, 'C');
    ll.show();
    std::cout << "\n";

    ll.remove(5);
    std::cout << ll.get_size() << "\n";

    pass += assert('\0', ll.get(5), "remove last");
    ll.show();
    std::cout << "\n";
    ll.insert(5, 'n');
    ll.show();
    ll.remove(3);
    ll.show();
    pass += assert('o', ll.get(3), "remove middle");
    std::cout << pass << "/3 Tests Passed";
}

void full_test() {
    int pass = 0;
    std::cout << "========== Full Test ==============\n";
    LinkedList ll;
    ll.insert(0, 'C');
    ll.insert(1, 'a');
    ll.insert(2, 'r');
    ll.insert(3, 's');
    ll.insert(4, 'o');
    ll.insert(5, 'n');
    test("Carson", ll.get_size(), ll);

    ll.remove(0);
    pass += test("arson", ll.get_size(), ll);

    ll.remove(ll.get_size()-1);
    pass += test("arso", ll.get_size(), ll);

    ll.remove(2);
    pass += test("aron", ll.get_size(), ll);
    std::cout << "Tests Passed: " << pass << "/3\n";
    std::cout << "===================================\n";
}


int main() {
    full_test();
    return 0;
}