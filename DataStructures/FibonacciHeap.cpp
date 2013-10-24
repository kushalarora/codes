#include<iostream>
#include "FibonacciNode.hpp"
#include<math.h>
using namespace std;

template<class T>
class FibonacciHeap {
    private:
        FibonacciNode<T>* Min;
        int nNodes;
        void consolidate();
        void cut(FibonacciNode<T>* node1, FibonacciNode<T>* node2);
        void cascadingCut(FibonacciNode<T>* node);
        void insertInList(FibonacciNode<T>** pList, FibonacciNode<T>* node);
        void insertInRootList(FibonacciNode<T>* node) {
            insertInList(&Min, node);
        }
        void meldLists(FibonacciNode<T>* node1, FibonacciNode<T>* node2);
        void removeFromList(FibonacciNode<T>** pList, FibonacciNode<T>* node);
        void heapLink(FibonacciNode<T>* node, FibonacciNode<T>* node2);
        void printList(FibonacciNode<T>* node);
    public:
        FibonacciHeap() {
            nNodes = 0;
            Min = NULL;
        }
        int getNodeCount() {return nNodes;}
        FibonacciNode<T>* getMinNode() {return Min;}
        void insertNode(FibonacciNode<T>* node);
        void meld(FibonacciHeap<T>* H2);
        FibonacciNode<T>* extractMin();
        void decreaseKey(FibonacciNode<T>* node, T key);
        void deleteNode(FibonacciNode<T>* node);
        void setMin(FibonacciNode<T>* node) {this->Min = node;}
        void printHeap();
        ~FibonacciHeap();
};

template<class T>
void FibonacciHeap<T>::insertNode(FibonacciNode<T>* node) {
    insertInRootList(node);
    if (Min == NULL || Min->getKeyVal() > node->getKeyVal()) {
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
        if (H2_min->getKeyVal() < H1_min->getKeyVal())
            this->Min = H2_min;
    }
    this->nNodes += H2->getNodeCount();
    H2->setMin(NULL);
}

template<class T>
void FibonacciHeap<T>::meldLists(FibonacciNode<T>* node1, FibonacciNode<T>* node2) {
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
void FibonacciHeap<T>::insertInList(FibonacciNode<T>** pList, FibonacciNode<T>* node) {
    if(node == NULL)
        return;
    FibonacciNode<T>* pNode = *pList;
    if (pNode == NULL) {
        node->setLeftSibling(node);
        node->setRightSibling(node);
        *pList = node;
    } else {
        node->setLeftSibling(pNode->getLeftSibling());
        pNode->getLeftSibling()->setRightSibling(node);

        node->setRightSibling(pNode);
        pNode->setLeftSibling(node);
    }
}

template<class T>
FibonacciNode<T>* FibonacciHeap<T>::extractMin() {
    FibonacciNode<T>* min = this->getMinNode();
    if (min != NULL) {
        FibonacciNode<T>* pointedChild = min->getChild();
        FibonacciNode<T>* temp = pointedChild;
        FibonacciNode<T>* child_ptr;
        while ((temp = min->getChild()) != NULL) {
            temp->setParent(NULL);
            removeFromList(&child_ptr, temp);
            min->setChild(child_ptr);
            insertInRootList(temp);
        }
        // remove min
        removeFromList(&Min, min);
        nNodes--;
        cout<<"Extracted Min"<<endl;
        printHeap();
        if (Min != NULL)
            consolidate();
    }
    return min;
}
template<class T>
void FibonacciHeap<T>::removeFromList(FibonacciNode<T>** pList, FibonacciNode<T>* node) {
    if (pList == NULL || node == NULL)
        return;
    FibonacciNode<T>* right = node->getRightSibling();
    FibonacciNode<T>* left = node->getLeftSibling();
    if (node == right || node == left) {
        *pList = NULL;
    } else {
        left->setRightSibling(right);
        right->setLeftSibling(left);
        *pList = right;
    }
}

template<class T>
void FibonacciHeap<T>::consolidate() {
    int max_deg = ceil(log(getNodeCount())) + 1;
    FibonacciNode<T>* Arr[max_deg];
    for (int i = 0; i < max_deg; i++) {
        Arr[i] = NULL;
    }

    // traverse the root list of Heap
    FibonacciNode<T>* temp;
    FibonacciNode<T>* temp2;
    while ((temp = getMinNode()) != NULL) {
        int deg = temp->getDegree();
        removeFromList(&Min, temp);
        while (Arr[deg] != NULL) {
            temp2 = Arr[deg];
            if (temp->getKeyVal() < temp2->getKeyVal()) {
                heapLink(temp, temp2);
            } else {
                heapLink(temp2, temp);
                temp = temp2;
            }
            Arr[deg] = NULL;
            deg++;
       }
       Arr[deg] = temp;
    }

    Min = NULL;
    for (int i = 0; i < max_deg; i++) {
        if (Arr[i] != NULL) {
            insertInRootList(Arr[i]);
            if (Min == NULL || Min->getKeyVal() > Arr[i]->getKeyVal()) {
                Min = Arr[i];
            }
        }
    }
    cout<<"Consolidated Heap"<<endl;
    printHeap();
}
template<class T>
void FibonacciHeap<T>::heapLink(FibonacciNode<T>* node, FibonacciNode<T>* node2) {
    if (node == NULL || node2 == NULL)
        return;
    // remove node2 from root list and add as a child to node
    FibonacciNode<T>* child = node->getChild();
    insertInList(&child, node2);
    if (node->getChild() == NULL)
        node->setChild(node2);
    node2->setParent(node);
    node->incDegree();
    node2->setMark(false);
}

template<class T>
void FibonacciHeap<T>::printHeap() {
    if (Min != NULL)
        printList(Min);
    else
        cout << "Empty Heap" << endl;
}

template<class T>
void FibonacciHeap<T>::printList(FibonacciNode<T>* node) {
    cout << "\n"<< "|" << endl << "\\/" << endl;
    FibonacciNode<T>* temp = node;
    FibonacciNode<T>* child;
    FibonacciNode<T>* parent;
    do {
        cout << "(" << temp->getKeyVal();
        parent = temp->getParent();
        if (parent != NULL)
            cout << ", " << parent->getKeyVal();
        cout << ")" << "\t";
        child = temp->getChild();
        if (child != NULL)
            printList(child);
        temp = temp->getRightSibling();
    } while(temp != node);
    cout << "\n";
}
template<class T>
FibonacciHeap<T>::~FibonacciHeap() {
    if (Min != NULL)
        return;
    delete Min;
}
