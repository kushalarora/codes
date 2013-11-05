using namespace std;
#include<iostream>
#include<cassert>

#ifndef SIMPLE_BST
#define SIMPLE_BST
class Node {
    Node* lchild;
    Node* rchild;
    int value;
    int leftSize;
    public:
        Node() {
            lchild = NULL;
            rchild = NULL;
            value = -1;
            leftSize = 0;
        }
        Node(int val) {
            lchild = NULL;
            rchild = NULL;
            value = val;
            leftSize = 0;
        }
        int getValue() {
            return value;
        }
        Node* getLChild() {
            return lchild;
        }
        Node* getRChild() {
            return rchild;
        }
        void setRChild(Node* right) {
            rchild = right;
        }
        void setLChild(Node* left) {
            lchild = left;
        }

        void setValue(int val) {
            value = val;
        }
        int getLeftSize() {
            return leftSize;
        }
        void incLeftSize() {
            leftSize++;
        }
        void decLeftSize() {
            leftSize--;
        }
};
class BinarySearchTree {
    Node* root;
    void inOrderRoutine(Node* parent);
    void preOrderRoutine(Node* parent);
    void postOrderRoutine(Node* parent);
    Node* successorRoutine(Node* root);
    Node* predecessorRoutine(Node* parent);
    void deleteNodeRoutine(Node* node);
    Node* searchNodeRoutine(int val, bool isDelete);
    public:
        BinarySearchTree() {
            root = NULL;
        }
        bool isEmpty() {return root == NULL;};
        void insertNode(int val);
        void insertNode(Node* node);
        void deleteNode(int val);
        Node* searchNode(int val);
        void preOrder();
 		void postOrder();
        void inOrder();
        Node* successor(int val);
        Node* predecessor(int val);
        Node* getNodeByIndex(int index);
};
#endif
