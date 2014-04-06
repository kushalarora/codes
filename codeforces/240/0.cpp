#include<iostream>

using namespace std;


int main() {
    int n, m, b;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        a[n] = -1;

    int off_till = n;
    while (m--) {
        cin >> b;
        while(off_till >= b) {
           a[--off_till] = b;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] <<" ";
    }
    return 0;
}
