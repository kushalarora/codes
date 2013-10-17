#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include "../cpp/assert_w_msg.hpp"
#include<limits.h>
using namespace std;
const int MAXINPUT = 10000;
template<class T, class V> class Options {
    private:
        map<T, V> mp;
        V deflt;
        // returns user provided map value corresponding to input.
        void mapOption(T input, V* container);
    public:
        Options(int count, pair<T,V> prs[], V def);
        // For single valued input like "How many inputs you want?"
        void readOption(string message, V* container);
        // For reading multiple inputs
        void readOptionMultiple(string message, int size, V* container);
        // For reading inputs till carrige return
        void readOptionMultiple(string message, V* container, int c_size);

};

