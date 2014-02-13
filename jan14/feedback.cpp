#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

const string pattern1 = "101";
const string pattern2 = "010";

bool containsPattern(string s) {
    string ss;
    for (int i = 0; i < s.length() - 3; i++) {
        ss = s.substr(i, 3);

        if (ss == pattern1 ||
                ss == pattern2) {
            return true;
        }
    }
        return false;
}

int main() {
    int T;
    char c1, c2, c3;
    cin >> T;
    bool found;
    while(T--) {
        found = false;
        c1 = getchar();
        c2 = getchar();
        while (c2 != '\n') {
            c3 = getchar();
            cout << (c3 =='\n');
            if (c1 == '1') {
                if (c2 == '0' && c3 == '1') {
                    cout << "Good" << endl;
                    found = true;
                }
            } else {
                if (c2 == '1' && c3 == '0') {
                    cout << "Good" << endl;
                    found = true;
                }
            }
            if (found)
                break;
            c1 = c2;
            c2 = c3;
        }
        if (!found)
            cout << "Bad" << endl;
    }
    return 0;
}
