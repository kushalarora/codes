#include "FibonacciHeap.cpp"
#include<assert.h>


int main() {
    FibonacciHeap<int> mQ = FibonacciHeap<int>();
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        mQ.insertNode(new FibonacciNode<int>(arr + i));
    }
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
    assert(mQ.extractMin()->getKeyVal() == 10);
    assert(mQ.extractMin()->getKeyVal() == 20);
    assert(mQ.extractMin()->getKeyVal() == 30);
    assert(mQ.extractMin()->getKeyVal() == 40);
    assert(mQ.extractMin()->getKeyVal() == 50);
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
    for (int i = 0; i < 5; i++) {
        mQ.insertNode(new FibonacciNode<int>(arr + i));
    }
    mQ.printHeap();
    mQ.extractMin();
    mQ.printHeap();
    cout<<"Decreasing Key 50 to 5"<<endl;
    FibonacciNode<int>* node = mQ.getNodeByVal(50);
    mQ.decreaseKey(node, new int(5));
    mQ.printHeap();
    assert(mQ.extractMin()->getKeyVal() == 5);
    return 0;
}
