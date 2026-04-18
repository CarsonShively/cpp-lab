#ifndef BST_H
#define BST_H

class Bst {
    struct Node {
        int value;
        Node* left;
        Node* right;
    };

    Node* root;
    int size;

    // recurse for each sub tree
    void recurse_insert(Node* node, int value);
    bool recurse_find(Node* node, int value) const;
    void recurse_destructor(Node* node);
    void recurse_print(Node* node) const;
    void recurse_in_order(Node* node) const;

public:
    // in order, pre order, post order
    Bst();
    ~Bst();
    void insert(int value);
    void remove(int value);
    bool is_found(int value) const;
    void print_nodes() const;
    int get_size() const;
    void in_order_traversal() const;

};

#endif