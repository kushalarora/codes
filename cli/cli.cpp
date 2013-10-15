#include "cli.hpp"

template<class T, class V>
CLI<T,V>::CLI(int count, pair<T,V> prs[], V def) {
    deflt = def;
    for (int i = 0; i < count; i++) {
        mp.insert(prs[i]);
    }
}

template<class T, class V>
void CLI<T,V>::readInput(string message, V* container) {
    // reset container
    *container = 0;
    cout<<message<<"\t";
    T input;
    cin >> input;
    mapInput(input, container);
}

template<class T, class V>
void CLI<T,V>::mapInput(T input, V* container) {
    typename map<T, V>::iterator it =  mp.find(input);
    if (it != mp.end())
        *container = it->second;
}

template<class T, class V>
void CLI<T,V>::readInputMultiple(string message, int size, V* container) {
    for (int i = 0; i < size; i++) {
        readInput(message, container++);
    }
}

template<class T, class V>
void CLI<T,V>::readInputMultiple(string message, V* container, int c_size) {
    string inputStr;
    cout<<message<<"\t";

    // flush cin buffer for any previous value
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, inputStr);
    int j = 0, k = 0;
    for (int i = 0; i <= inputStr.length(); i++) {
        if (i == inputStr.length()|| inputStr[i] == ' ') {
            assert(k < c_size);
            mapInput(inputStr.substr(j, i - j), container++);
            i = i + 1;
            j = i;
            k++;
        }
    }
}

typedef pair<string, int> cli_pair;
int main(int argc, char** argv) {
    int* inp1;
    cli_pair prs[] = {
        cli_pair("hello", 1),
        cli_pair("hi", 2),
        cli_pair("world", 3)
    };
    CLI<string, int> *cli = new CLI<string, int>(3, prs, 0);
    int out[10];
    cli->readInput("say hello", &out[0]);
    assert(1 == out[0]);

    cli->readInputMultiple("Say hello, hi and world one at a time", 3, out);
    for (int i = 0; i < 3; i++)
        assert(i+1 == out[i]);
    cli->readInputMultiple("Say hello hi world seperated by space, followed by carrige return", out, 3);
    for (int i = 0; i < 3; i++)
        assert(i+1 == out[i]);
}
