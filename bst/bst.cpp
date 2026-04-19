/**
 * resize linux disk
 * 
 * write a standard library (optimised and enginered end of a concept)
 * 
 * im implementing concepts
 * libraries are the optmised end of a concept
 * 
 * data structures are libraries, they should not control creating entity objects
 * 
 */

#include "bst.h"
#include <iostream>
#include <queue>
#include <vector>

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

// handle node call on other 2 based on order, return on base case
void Bst::recurse_in_order(Node* node) const {
    if (node == nullptr) { // if its a nullptr send it back up
        return;
    }
    // call on left, then print node, then on right
    recurse_in_order(node->left);
    std::cout << node->value <<"\n";
    recurse_in_order(node->right);
}

void Bst::preorder_traversal() const {
    if (root != nullptr) {
        recurse_preorder(root);
    }
    std::cout << "\n";
}

void Bst::recurse_preorder(Node* node) const {
    if (node == nullptr) {// current node not next node
        return;
    }

    std::cout << node->value << "\n";
    recurse_preorder(node->left);
    recurse_preorder(node->right);

}

void Bst::postorder_traversal() const {
    if (root != nullptr) {
        recurse_postorder(root);
    }
    std::cout << "\n";
}

void Bst::recurse_postorder(Node* node) const {
    if (node == nullptr) { // base case
        return;
    }
    recurse_postorder(node->left);
    recurse_postorder(node->right);
    std::cout << node->value << "\n";
}
// level order
// add root to queue
// handle front (current)
// add children to queue
//pop current
//either dont add nullptrs to queue or skip if in queue
void Bst::levelorder_traversal() const {
    // queue of pointers to nodes, null pointer is still a pointer
    std::queue<Node*> q;
    q.push(root);

    // level order = put into queue then handle queue items children
    while(!q.empty()) {
        Node* current = q.front(); // pop does not get the value
        if (current == nullptr) {
            q.pop();
            continue;
        }
        std::cout << current->value << "\n";
        q.push(current->left);
        q.push(current->right);
        q.pop();
    }
}

void Bst::level_print() const {
    std::vector<std::vector<int>> levels;
    // max nodes = 2^#-levels - 1
    // when creating an array on stack you have to set the size so compiler knows how big the stack frame should be
    // a set size is not often the best choice
    // vector and string both work for chars but string is more optimised for that case

    std::queue<Node*> q;
    if (root == nullptr) {
        return;
    }
    q.push(root);
    
    // key == double loop without hurting performance
    // O(n) becuase all nodes are process only once
    while (!q.empty()) {
        std::vector<int> level;
        int q_size = q.size();
        for (int i=0; i<q_size; i++) {// first index is inside
            
            Node* node = q.front();
            level.push_back(node->value); // set position = to value, need a method so it can resize when needed
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
            q.pop();
            
            
        }
        levels.push_back(level); // have to use push back for each level of a vector

    }
    
    // pointer is not an object, pointer to an object so it doesnt need &

    // for (type) : vector

    // work with auto in general c++ later, be explicit right now
    for (const std::vector<int>& row : levels) { // each type of this size in levels, each row is vector<int> in levels, vector is an object == pass address
        // for each x size in y
        for (int i : row) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

}

// 2 vector keys = : for looping through a vector, push_back for adding to a vector
// create temp vector and push back for 2d vector

// in order predecessor == largest in left sub tree
// in order sucessor == smallest in right sub tree

// use sucessor here

void Bst::remove(int value) {
    // recurssion fixes the subtree of the node passed in
    // returns the node passed in
    // set the pointer equal to this returned node 
    root = recurse_remove(root, value);


}

// for a return type use ::
Bst::Node* Bst::recurse_remove(Node* node, int value) {

    if (!is_found(value)) {
        return node;
    }

    // return the node passed in
    // fixed sub tree

    // pass in node to fix and return that fixed node
    // node == node + sub tree under it
    // fix == delete in this case

    if (node == nullptr) {// there is no subtree
        return nullptr; // return the value for clarity
    }

    if (value < node->value) { // delete is in left sub tree
        node->left = recurse_remove(node->left, value); // node->left = root of left sub tree
        return node; // return the node passed in
        // with the fixed left sub tree
    }   

    // fix node and return it so you can set it equal
    if (node->value < value) { // delete in in right sub tree

        // pointer to right node = fixed right node

        node->right = recurse_remove(node->right, value); // fix the right sub tree with root = node->right
        return node; // return node passed into this recursion
        // with the fixed right sub tree
    } 

    // passes all previous cases no action
    
    // node passed in is the one to delete and return this node
    // delete cases


    // can only be 1 case
    if (node->left == nullptr && node->right == nullptr) { // no children
        delete node; // just remove
        return nullptr; // node->right/left will point to this returned value

    }



    // return the node you want node->left/right to point to 
    if (node->left != nullptr && node->right == nullptr) {
        Node* tmp = node->left;
        delete node;
        return tmp;

    } 
    
    if (node->right != nullptr && node->left == nullptr) {
        Node* tmp = node->right;
        delete node;
        return tmp;
    } 
    

        
    
    Node* current = node->right;
    while (current->left != nullptr) {
        current = current->left; // current == successor
    }



    node->value = current->value; // change the value so you dont need to change pointers
    // just gave it the smallest value from the right sub tree
    node->right = recurse_remove(node->right, current->value); // remove that node from the right sub tree



    return node;



}