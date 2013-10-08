#include "cli.hpp"

template<class T, class V>
V CLI<T,V>::readInput(string message, V def) {
    cout<<message;
    T input;
    cin >> input;
    return mapInput(input, def);
}

template<class T, class V>
V CLI<T,V>::mapInput(T input, V def) {
    typename map<T, V>::iterator it =  mp.find(input);
    if (it.size() == 1) {
        return it->second;
    }
    return def;
}

template<class T, class V>
V* CLI<T,V>::readInputMultiple(string message, int size, V def) {
    V out[size];
    for (int i = 0; i < size; i++) {
        out[i] = readInput(message, def);
    }
    return &out;
}

template<class T, class V>
V* CLI<T,V>::readInputMultiple(string message, V def) {
    string inputStr;
    getline(cin, inputStr);
    int j = 0;
    vector<V> out;
    for (int i = 0; i < inputStr.length(); i++) {
        if (inputStr[i] == ' ') {
            out.push_back(mapInput(inputStr.substr(j, i - j)));
            i = i + 1;
            j = i;
        }
    }
    return &out;
}

int main(int argc, char** argv) {
}

