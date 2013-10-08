#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
using namespace std;

template<class T, class V> class CLI {
    private:
        map<T, V> mp;
        V mapInput(T input, V def);
    public:
        CLI(map<T, V> map) {
            mp = map;
        }
        // For single valued input like "How many inputs you want?"
        V readInput(string message, V default);
        // For reading multiple inputs
        V* readInputMultiple(string message, int size, V def);
        // For reading inputs till carrige return
        V* readInputMultiple(string message, V def);

};

template<class T> class CLI {
    public:
        CLI() {};

};
