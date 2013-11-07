using namespace std;

#include "../../cpp/utils.hpp"

#include<iostream>
#include<cassert>
#include<string>

#ifndef __SIMPLE_BST__
#define __SIMPLE_BST__
template<class T, class Y>
class Node {
    Node* lchild;
    Node* rchild;
    T key;
    Y value;
    long long id;
    int leftSize;
    public:
        Node& operator=( const Node& rhs ) {
            value = rhs.getValue();
            key = rhs.getKey();
        }

        Node() {
            lchild = NULL;
            rchild = NULL;
            key = -1;
            leftSize = 0;
        }
        Node(T ky, Y val) {
            lchild = NULL;
            rchild = NULL;
            key = ky;
            value = val;
            leftSize = 0;
        }
        Node(const Node& old) {
            key = old.getKey();
            value = old.getValue();
        }
        inline T getValue() {
            return value;
        }
        inline T getkey() {
            return key;
        }
        inline Node* getLChild() {
            return lchild;
        }
        inline Node* getRChild() {
            return rchild;
        }
        inline void setRChild(Node* right) {
            rchild = right;
        }
        inline void setLChild(Node* left) {
            lchild = left;
        }
        inline int getLeftSize() {
            return leftSize;
        }
        inline void incLeftSize() {
            leftSize++;
        }
        inline void decLeftSize() {
            leftSize--;
        }
};

template<class T, class Y>
class BinarySearchTree {
    typedef Node<T, Y> node;
    typedef Node<T, Y>* node_ptr;
    node_ptr root;
    void inOrderRoutine(node_ptr parent);
    void preOrderRoutine(node_ptr parent);
    void postOrderRoutine(node_ptr parent);
    node_ptr successorRoutine(node_ptr root);
    node_ptr predecessorRoutine(node_ptr parent);
    void deleteNodeRoutine(node_ptr node);
    node_ptr searchNodeRoutine(T key, bool isDelete);
    public:
        BinarySearchTree() {
            root = NULL;
        }
        bool isEmpty() {return root == NULL;};
        void insertNode(T key, Y value);
        void insertNode(node_ptr node);
        void deleteNode(T key);
        node_ptr searchNode(T key);
        void preOrder();
 		void postOrder();
        void inOrder();
        node_ptr successor(T key);
        node_ptr predecessor(T key);
        node_ptr getNodeByIndex(int index);
};

#endif
