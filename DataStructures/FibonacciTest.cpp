#include "FibonacciHeap.hpp"
#include<assert.h>

#define RUN 5000
int main() {
    FibonacciHeap<int> mQ = FibonacciHeap<int>();
    int arr[RUN];
    for (int i = 0; i < RUN; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < RUN; i++) {
        mQ.insertNode(arr + i, arr[i]);
    }
    //cout<<"Printing Heap"<<endl;
    //mQ.printHeap();
    for (int i = 0; i < RUN; i++) {
        assert(*(mQ.extractMin()) == i);
    }
    cout<<"Printing Heap"<<endl;
    //mQ.printHeap();
    for (int i = 0; i < RUN/2; i++) {
        mQ.insertNode(arr + i, arr[i]);
    }
    cout<<"Printing Heap"<<endl;
    //mQ.printHeap();
    cout<<"Decreasing Key 50 to 5"<<endl;
    mQ.decreaseKey(arr +4, -1);
    //mQ.printHeap();
    assert(*mQ.extractMin() == 4);
    return 0;
}
