/**
 * fully automated tests later (own section)
 */

#include "bst.h"
#include <iostream>

void test() {
    // endle is a must when debugging
    Bst tree;

    tree.insert(50);
    tree.insert(100);
    tree.insert(25);


    tree.insert(15);
    tree.insert(20);

    tree.insert(60);
    tree.insert(80);


    tree.insert(75);
    tree.insert(85);

    tree.insert(5);
    tree.insert(10);

    tree.insert(90);
    tree.insert(1);

    tree.level_print();

    std::cout << "\n";

    tree.remove(60);
    tree.level_print();

    std::cout << "\n";

    tree.level_print();

    std::cout << "\n";

    tree.remove(80);
    tree.level_print();

    std::cout << "\n";

    tree.level_print();

    std::cout << "\n";

    tree.remove(85);
    tree.level_print();

    std::cout << "\n";

    tree.level_print();

    std::cout << "\n";

    tree.remove(75);
    tree.level_print();

    std::cout << "\n";

    tree.level_print();

    std::cout << "\n";

    tree.remove(25);
    tree.level_print();

    std::cout << "\n";

    

}

int main() {
    test();
    return 0;
}