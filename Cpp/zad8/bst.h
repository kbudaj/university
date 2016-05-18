//
// Created by kb on 17/5/16.
//

#ifndef BST_H
#define BST_H

#include <cstddef>
#include <iostream>

using namespace std;

namespace structures {

template <class T>
class BST {
private:
    struct node {
        node* left;
        node* right;
        T value;
    };

    node* root;

public:
    BST() {
        this->root = NULL;
    }
    bool isEmpty() const { return this->root == NULL;};
    void insert(T);
    void insert_helper(node*&, T);
    void print();
    void print_helper(node*);
    bool search(T);
    bool search_helper(node*, T);
    //bool delete(T);
};

template <class T>
void BST<T>::insert_helper(node*& root, T value) {
    if(root == NULL) { // New tree
        node* n = new node;
        n->value = value;
        n->left = NULL;
        n->right = NULL;
        root = n;
    } else if (value < root->value){
        insert_helper(root->left, value);
    } else {
        insert_helper(root->right, value);
    }
}

template <class T>
void BST<T>::insert(T value) {
    insert_helper(this->root, value);
}

template<class T>
void BST<T>::print_helper(node* n) {
    if (n == NULL) {
        return;
    }
    print_helper(n->left);
    cout << n->value << " ";
    print_helper(n->right);
}

template<class T>
void BST<T>::print() {
	print_helper(this->root);
}

template<class T>
bool BST<T>::search(T value) {
	return search_helper(this->root, value);
}

template<class T>
bool BST<T>::search_helper(node* root, T value) {
    if (root == NULL) {
        return false;
    }

    if (value == root->value) {
        return true;
    } else if (value < root->value ){
        return search_helper(root->left, value);
    } else {
        return search_helper(root->right, value);
    }
}

}
#endif
