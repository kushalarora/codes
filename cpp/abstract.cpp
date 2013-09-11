// Example of an non instantiable abstract class.
#include<iostream>
#include<cassert>
#include<string>

using namespace std;
template<class T> class Stack {
    public:
        virtual void push(T) = 0;   // defines pure virtual functions.
        virtual T pop() {};
};

template<class T> class AStack : public Stack<T> {
    T* arr;
    int sp;
    int sz;
    public:
        AStack(int s) {
            if (s < 0) assert(0);
            arr = new T[sz = s];
            sp = 0;
        }

        ~AStack() {
            delete[] arr;
        }

        void push(T val) {
            arr[sp] = val;
            sp++;
        }

        T pop() {
            if (sp < 0) assert(0);
            return arr[--sp];
        }


};
int main() {
        AStack<string> as(2);
        as.push("Hello");
        as.push("World");

        cout<<as.pop()<<"\n"<<as.pop()<<"\n";
    return 0;
}
