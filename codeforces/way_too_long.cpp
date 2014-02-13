#include<iostream>
#include<string>

using namespace std;

int main() {
    int n, len;
    string word;
    cin >> n;

    while (n--) {
        cin >> word;
        len = word.length();

        if (len > 10)
            cout << word.substr(0, 1) << len - 2 << word.substr(len - 1, 1) << endl;
        else
            cout << word << endl;
    }
    return 0;
}
