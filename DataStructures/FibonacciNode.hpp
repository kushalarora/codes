#include<iostream>
using namespace std;
template<class T>
class FibonacciNode {
    private:
        T* key;
        FibonacciNode* left;
        FibonacciNode* right;
        int degree;
        bool mark;
        FibonacciNode* parent;
        FibonacciNode* child;

    public:
        FibonacciNode(T* key) {
            this->key = key;
            left = NULL;
            right = NULL;
            degree = 0;
            mark = false;
            parent = NULL;
            child = NULL;
        }
        T* getKey() {return key;}
        void setKey(T* key) {this->key = key;}
        FibonacciNode* getRightSibling() {return right;}
        void setRightSibling(FibonacciNode* right) {this->right = right;}
        FibonacciNode* getLeftSibling() {return left;}
        void setLeftSibling(FibonacciNode* left) {this->left = left;}
        int getDegree(){return degree;}
        bool getMark() {return mark;}
        void setMark() {this->mark = mark;}
        void setParent(FibonacciNode* parent) {this->parent = parent;}
        FibonacciNode* getParent() {return parent;}
        void setChild(FibonacciNode* child) {this->child = child;}
        FibonacciNode* getChild() {return child;}
        void incDegree() {degree++;}
        void decDegree() {degree--;}
        void setDegree() {this->degree = degree;}
};
