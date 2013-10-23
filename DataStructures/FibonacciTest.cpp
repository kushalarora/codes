#include "FibonacciHeap.cpp"


int main() {
    FibonacciHeap<int> mQ = FibonacciHeap<int>();
    mQ.insertNode(new FibonacciNode<int>(new int(10)));
    mQ.insertNode(new FibonacciNode<int>(new int(20)));
    mQ.insertNode(new FibonacciNode<int>(new int(30)));
    mQ.insertNode(new FibonacciNode<int>(new int(40)));
    mQ.insertNode(new FibonacciNode<int>(new int(50)));
    mQ.printHeap();
    return 0;
}
