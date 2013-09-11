#include<iostream>
#include<cassert>
#include<string>

using namespace std;
template<class T> class Vector {
    T* v;
    int sz;

    public:
        Vector (int s) {
            if (s <= 0) {cout << "Bad Size"; assert(0);}
            v = new T[sz = s];
        }
        T& operator[](int i);
        int size() {return sz;};

        void setValue(int i, T val) {
            v[i] = val;
        }

        void printValue(int i) {
            if (i >= sz) {cout<< "Bad Index"; assert(0);}
            cout<<v[i];
        }
};

template<class T> T& Vector<T>::operator[](int i) {
    return v[i];
}


int main() {
    Vector<string> v1(2);
    v1.setValue(0, "Hello");
    v1.setValue(1, "World");

    v1.printValue(0);
    v1.printValue(1);

    return 0;
}
