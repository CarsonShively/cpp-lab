/**
 * resize linux disk
 * 
 */

#include "bst.h"
#include <iostream>

Bst::Bst() {
    root = nullptr;
    size = 0;
}

void Bst::insert(int value) {
    if (root == nullptr) {
        Node* first = new Node{value, nullptr, nullptr};
        root = first;
        size++;
    } else {
        if (is_found(value)) {
            return;
        } 
        recurse_insert(root, value);
    }
}


// node is a pointer to the node object
// pointer to object == -> to access fields, type of field doesnt matter
void Bst::recurse_insert(Node* node, int value) {
    if (value < node->value) {
        if (node->left == nullptr) {
            Node* new_node = new Node{value, nullptr, nullptr};
            node->left = new_node;
            size++;
        } else {
            recurse_insert(node->left, value);
        }
    } else {
        if (node->right == nullptr) {
            Node* new_node = new Node{value, nullptr, nullptr};
            node->right = new_node;
            size++;
        } else {
            recurse_insert(node->right, value);
        }
    }
}

bool Bst::is_found(int value) const {
    if (root == nullptr) {
        return false;
    }

    return recurse_find(root, value);
}


// when recursing with non void method type have to return the recursion
bool Bst::recurse_find(Node* node, int value) const {
    if (node->value == value) {
        return true;
    } else if (value < node->value) {
        if (node->left == nullptr) {
            return false;
        } else {
            // without return this would == boolean and sit here, not return upwards
            // key == if not void return the recursion
            return recurse_find(node->left, value);
        }
    } else {
        if (node->right == nullptr) {
            return false;
        } else {
            return recurse_find(node->right, value);
        }
    }

}

Bst::~Bst() {
    recurse_destructor(root);
}

void Bst::recurse_destructor(Node* node) {
    if (node->left != nullptr) {
        recurse_destructor(node->left);
    }
    if (node->right != nullptr) {
        recurse_destructor(node->right);
    }
    delete node;
}

void Bst::print_nodes() const {
    recurse_print(root);
}

void Bst::recurse_print(Node* node) const {
    if (node != nullptr) {
        std::cout << "parent= " << node->value;
        if (node->left == nullptr) {
            std::cout << " left child: null";
        } else {
            std::cout << " left child: " << node->left->value;
        }
        if (node->right == nullptr) {
            std::cout << " right child: null";
        } else {
            std::cout << " right child: " << node->right->value;
        }
        std::cout << "\n";
        recurse_print(node->left);
        recurse_print(node->right);
    }

}

int Bst::get_size() const {
    return size;
}

//in order traversal

void Bst::in_order_traversal() const {
    if (root != nullptr) {
        recurse_in_order(root);
    }
    std::cout << "\n";
}

void Bst::recurse_in_order(Node* node) const {
    if (node->left == nullptr) {
        std::cout << node->value;
        if (node->right != nullptr) {
            std::cout << "debug\n";
            recurse_in_order(node->right);
        }

    } else {
        recurse_in_order(node->left);
    }
}