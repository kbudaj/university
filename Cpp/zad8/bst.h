//
// Created by kb on 17/5/16.
//

#ifndef BST_H
#define BST_H

#include <cstddef>
#include <iostream>
#include <stack>

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
    bool operator()(const T& lhs, const T& rhs ) const;
    void remove(T);
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
    } else if (value > root->value){
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

template <class T>
void BST<T>::remove(T value) {
	bool found = false;
	if(isEmpty())
	{
		return;
	}

	node* current;
	node* parent;
	current = root;
	parent = (node*)NULL;

	while(current != NULL) {
		if(current->value == value) {
			found = true;
			break;
		} else {
			parent = current;
			if(value>current->value) {
                current = current->right;
            } else {
                current = current->left;
            }
		}
	}
	if(!found) {
		return;
	}

	if((current->left == NULL && current->right != NULL)|| (current->left != NULL
		&& current->right == NULL)) {
		if (current->left == NULL && current->right != NULL) {
			if (parent->left == current) {
				parent->left = current->right;
				delete current;
			} else {
				parent->right = current->right;
				delete current;
			}
		} else {
			if (parent->left == current) {
				parent->left = current->left;
				delete current;
			} else {
				parent->right = current->left;
				delete current;
			}
		}
		return;
	}

	if (current->left == NULL && current->right == NULL)
	{
		if (parent == NULL)
		{
			delete current;

		} else
			if(parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
			delete current;
			return;
	}

	if (current->left != NULL && current->right != NULL) {
		node* n1;
		n1 = current->right;
		if((n1->left == NULL) && (n1->right == NULL)) {
			current = n1;
			delete n1;
			current->right = NULL;
		} else {
			if((current->right)->left != NULL) {
				node* lcurr;
				node* lcurrp;
				lcurrp = current->right;
				lcurr = (current->right)->left;
				while (lcurr->left != NULL){
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				current->value = lcurr->value;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				node* tmp;
				tmp = current->right;
				current->value = tmp->value;
				current->right = tmp->right;
				delete tmp;
			}

		}
		return;
	}

}

}
#endif
