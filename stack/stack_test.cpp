#include "stack.h"
#include <iostream>
#include <string>

int assert(int expected, int output) {
    if (expected == output) {
        return 1;
    } else {
        return 0;
    }
}

void test_stack() {
    int pass = 0;
    std::cout << "=========== Stack =============\n";
    Stack s;
    s.push(1, 2);
    s.push(3, 4);
    s.push(5, 6);
    Stack::Thread out = s.pop();
    pass += assert(out.start, 5);
    pass += assert(out.end, 6);

    out = s.pop();
    pass += assert(out.start, 3);
    pass += assert(out.end, 4);

    out = s.pop();
    pass += assert(out.start, 1);
    pass += assert(out.end, 2);
    std::cout << pass << "/6\n";
}

int main() {
    test_stack();
    return 0;
}