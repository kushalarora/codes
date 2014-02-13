#include<iostream>
using namespace std;


int main() {
    int n, k, num, kth, count = 0;
    cin >>n >> k;

    for(int i = 0; i < k; i++) {
        cin >> num;
        if (num == 0)
            break;
        count++;
    }

    if (k == n || num == 0) {
        cout << count;
        return 0;
    }

    kth = num;
    for(int i = k; i < n; i++) {
        cin >> num ;
        if (num < kth)
            break;

        count++;
    }
    cout << count;
    return 0;
}
