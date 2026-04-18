/**
 * manual tests
 * NO automated tests
 * automated tests later
 */

#include "bst.h"
#include <iostream>

void test() {
    // endle is a must when debugging
    Bst tree;

    tree.insert(5);
    tree.insert(10);
    tree.insert(3);

    tree.insert(1);
    tree.insert(4);

    tree.insert(8);
    tree.insert(11);


    tree.in_order_traversal();

}

int main() {
    test();
    return 0;
}