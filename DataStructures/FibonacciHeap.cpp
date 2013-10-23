#include<iostream>
#include "FibonacciNode.hpp"
#include<math.h>
#include "../cpp/utils.hpp"
using namespace std;

template<class T>
class FibonacciHeap {
    private:
        FibonacciNode<T>* Min;
        int nNodes;
        void consolidate();
        void cut(FibonacciNode<T>* node1, FibonacciNode<T>* node2);
        void cascadingCut(FibonacciNode<T>* node);
        void insertInList(FibonacciNode<T>* pList, FibonacciNode<T>* node);
        void insertInRootList(FibonacciNode<T>* node) {
            insertInList(Min, node);
        }
        void meldLists(FibonacciNode<T>* node1, FibonacciNode<T>* node2);
        void removeFromList(FibonacciNode<T>* pList, FibonacciNode<T>* node);
        void heapLink(FibonacciNode<T>* node, FibonacciNode<T>* node2);
    public:
        FibonacciHeap() {
            nNodes = 0;
            min = NULL;
        }
        int getNodeCount() {return nNodes;}
        FibonacciNode<T>* getMinNode() {return min;}
        void insertNode(FibonacciNode<T>* node);
        void meld(FibonacciHeap* H2);
        FibonacciNode<T>* extractMin();
        void decreaseKey(FibonacciNode<T>* node, T key);
        void deleteNode(FibonacciNode<T>* node);
        void setMin(FibonacciNode<T>* node) {this->Min = node;}
};

template<class T>
void FibonacciHeap<T>::insertNode(FibonacciNode<T>* node) {
    insertInRootList(node);
    if (Min == NULL || Min->getKey() < node->getKey()) {
        Min = node;
    }
    nNodes++;
}
template<class T>
void FibonacciHeap<T>::meld(FibonacciHeap<T>* H2) {
    if (H2 == NULL || H2->getNodeCount() == 0 || H2->getMinNode() == NULL)
        return;

    FibonacciNode<T>* H2_min = H2->getMinNode();
    FibonacciNode<T>* H1_min = this->getMinNode();

    if (H1_min == NULL) {
        // Make H2's root list as H1's root list.
        this->Min = H2_min;
    } else {
        meldLists(H1_min, H2_min);
        // set new Minimum
        if (H2_min->getKey() < H1_min->getKey())
            this->min = H2_min;
    }
    H2->setMin(NULL);
    delete H2;
}

template<class T>
void meldLists(FibonacciNode<T>* node1, FibonacciNode<T>* node2) {
    if (node1 != NULL && node2 != NULL) {
        // join this's and H2's root lists.

        FibonacciNode<T>* temp = node1->getRightSibling();
        FibonacciNode<T>* temp2 = node2->getRightSibling();

        node1->setRightSibling(temp2);
        temp2->setLeftSibling(node1);

        node2->setRightSibling(temp);
        temp->setLeftSibling(node2);
    } else if (node1 = NULL)
        node1 = node2;

}

template<class T>
void FibonacciHeap<T>::insertInList(FibonacciNode<T>* pList, FibonacciNode<T>* node) {
    if(node == NULL)
        return;

    if (pList == NULL) {
        node->setLeftSibling(node);
        node->setRightSibling(node);
        pList = node;
    } else {
        node->setLeftSibling(pList->getLeftSibling());
        pList->getLeftSibling()->setRightSibling(node);

        node->setRightSibling(pList);
        pList->setLeftSibling(node);
    }
}

template<class T>
FibonacciNode<T>* FibonacciHeap<T>::extractMin() {
    FibonacciNode<T>* min = this->getMinNode();
    if (min != NULL) {
        FibonacciNode<T>* pointedChild = min->getChild();
        FibonacciNode<T>* temp = pointedChild;
        FibonacciNode<T>* temp2;
        do {
            temp->setParent(NULL);
            temp2 = temp->getRightSibling();
            insertInRootList(temp);
            temp = temp2;
        } while(temp != pointedChild);

        // remove min
        removeFromList(Min, min);

        if (min == min->getRightSibling())
            Min = NULL;
        else {
            Min = min->getRightSibling();
            consolidate();
        }
        nNodes--;
    }
    return min;
}
template<class T>
void FibonacciHeap<T>::removeFromList(FibonacciNode<T>* pList, FibonacciNode<T>* node) {
    if (pList == NULL || node == NULL)
        return;
    FibonacciNode<T>* right = node->getRightSibling();
    FibonacciNode<T>* left = node->getLeftSibling();
    if (node == right || node == left) {
        pList = NULL;
    } else {
        left->setRightSibling(right);
        right->setLeftSibling(left);
        pList = right;
    }
}

template<class T>
void FibonacciHeap<T>::consolidate() {
    int max_deg = ciel(log(getNodeCount()));
    FibonacciNode<T>* Arr[max_deg];
    for (int i = 0; i < max_deg; i++) {
        Arr[i] = NULL;
    }

    // traverse the root list of Heap
    FibonacciNode<T>* temp = getMinNode();
    FibonacciNode<T>* temp2;
    FibonacciNode<T>* right_sibling;
    while (temp = getMinNode() != NULL) {
        int deg = temp->getDegree();
        removeFromList(Min, temp);
        while (Arr[deg] != NULL) {
            temp2 = Arr[deg];
            if (temp->getKey() > temp2->getKey()) {
                heapLink(temp, temp2);
            } else {
                heapLink(temp2, temp);
            }
            Arr[deg] = NULL;
            deg++;
       }
       Arr[deg] = temp;
    }

    Min = NULL;
    nNodes = 0;
    for (int i = 0; i < max_deg; i++) {
        if (Arr[i] != NULL) {
            insertNode(Arr[i]);
        }
    }
}
template<class T>
void FibonacciHeap<T>::heapLink(FibonacciNode<T>* node, FibonacciNode<T>* node2) {
    if (node == NULL || node2 == NULL)
        return;
    // remove node2 from root list and add as a child to node
    insertInList(node->getChild(), node2);
    node->incDegree();
    node2->setMark(false);
}
