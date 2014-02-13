#include<iostream>
#include<string>
#include<cmath>

using namespace std;
inline bool matches101Or010(const string& s1) {
    int num = 0;
    int end = s1.length();
    cout << "hello"<<endl;
    for(int i = 0; i < end; i++) {
        num = (num << 1) + (s1[i] == '1' ? 1 : 0);
    }
    if (num == 2 || num == 5)
        return true;
    return false;
}

int main() {
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        bool found = false;
        for (int i = 0; i < s.length() - 2; i++) {
            if (matches101Or010(s.substr(i, 3))) {
                cout << "Good" << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Bad" << endl;
    }
}
