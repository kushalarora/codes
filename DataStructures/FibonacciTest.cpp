#include "FibonacciHeap.cpp"
#include<assert.h>


int main() {
    FibonacciHeap<int> mQ = FibonacciHeap<int>();
    mQ.insertNode(new FibonacciNode<int>(new int(10)));
    mQ.insertNode(new FibonacciNode<int>(new int(20)));
    mQ.insertNode(new FibonacciNode<int>(new int(30)));
    mQ.insertNode(new FibonacciNode<int>(new int(40)));
    mQ.insertNode(new FibonacciNode<int>(new int(50)));
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
    assert(mQ.extractMin()->getKeyVal() == 10);
    assert(mQ.extractMin()->getKeyVal() == 20);
    assert(mQ.extractMin()->getKeyVal() == 30);
    assert(mQ.extractMin()->getKeyVal() == 40);
    assert(mQ.extractMin()->getKeyVal() == 50);
    cout<<"Printing Heap"<<endl;
    mQ.printHeap();
    return 0;
}
