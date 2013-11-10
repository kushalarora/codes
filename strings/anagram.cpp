#include<iostream>
#include<string>
using namespace std;


int main() {
    int T, len, i;
    int a[256];
    string str;
    cin>>T;
    while(T--) {
        for (i = 0; i < 256; i++) {
            a[i] = 0;
        }

        cin >> str;
        if (str.length() % 2 > 0) {
            cout << -1<<"\n";
            continue;
        }

        len = str.length() / 2;

        for (i = 0; i < len; i++) {
            a[str[i]]++;
        }

        for (i = 0; i < len; i++) {
            char c = str[i + len];
            if (a[c] > 0) {
                a[c]--;
            }
        }
        int count = 0;
        for (i = 0; i < 256 ; i++) {
            count += a[i];
        }
        cout << count<<"\n";
    }
}
