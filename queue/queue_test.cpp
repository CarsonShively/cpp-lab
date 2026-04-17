#include "queue.h"
#include <iostream>

// cant compare objects directly becuase of padding, only works for primitive types

int assert(long expected, long output) {
    if(expected == output) {
        return 1;
    } else {
        return 0;
    }
}

void test() {
    int pass = 0;
    Queue que;
    que.enqueue(2);
    que.enqueue(4);
    que.enqueue(6);

    long out = que.dequeue();
    pass += assert(2, out);

    out = que.dequeue();
    pass += assert(4, out);

    out = que.dequeue();
    pass += assert(6, out);

    std::cout << "======== Test ===========\n";
    std::cout << "Tests Passed: " << pass << "/3\n";
}

int main() {
    test();
    return 0;
}