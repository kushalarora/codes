#include "FibonacciHeap.hpp"
#include<assert.h>


int main() {
    FibonacciHeap<int> mQ = FibonacciHeap<int>();
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        mQ.insertNode(arr + i);
    }
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
    assert(*(mQ.extractMin()) == 10);
    assert(*mQ.extractMin() == 20);
    assert(*mQ.extractMin() == 30);
    assert(*mQ.extractMin() == 40);
    assert(*mQ.extractMin() == 50);
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
    for (int i = 0; i < 5; i++) {
        mQ.insertNode(arr + i);
    }
    mQ.printHeap();
    mQ.extractMin();
    mQ.printHeap();
    cout<<"Decreasing Key 50 to 5"<<endl;
    FibonacciNode<int>* node = mQ.getNodeByVal(50);
    mQ.decreaseKey(node, new int(5));
    mQ.printHeap();
    assert(*mQ.extractMin() == 5);
    return 0;
}
