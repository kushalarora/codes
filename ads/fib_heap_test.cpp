#include "fheap.hpp"
#include<assert.h>

#define DEBUG
#define RUN 10
int main() {
    FibonacciHeap<int> mQ = FibonacciHeap<int>();
    int arr[RUN];
    for (int i = 0; i < RUN; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < RUN; i++) {
        mQ.insertNode(arr + i, arr[i]);
    }
#ifdef DEBUG
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
#endif
    for (int i = 0; i < RUN; i++) {
        assert(*(mQ.extractMin()) == i);
    }
#ifdef DEBUG
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
#endif
    for (int i = 0; i < RUN/2; i++) {
        mQ.insertNode(arr + i, arr[i]);
    }
#ifdef DEBUG
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
#endif

#ifdef DEBUG
    cout<<"Decreasing Key 50 to 5"<<endl;
#endif
    mQ.decreaseKey(arr +4, -1);
#ifdef DEBUG
    mQ.printHeap();
#endif
    assert(*mQ.extractMin() == 4);
    return 0;
}
