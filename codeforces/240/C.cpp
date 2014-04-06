#include<iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    if (k < n/2) {  // k less that mimum score that can be obtained on n numbers.
        cout << -1;
    } else if (k == 0 ||    // no move expected of participant
            n/2 == k) {     // # of can be met with \sum gcd(x, x+1)=1;
        for (int i = 1; i < n + 1; i++)
            cout << i << " ";
    } else if (n == 1) {
        cout << -1;     // k > 0 and only one number, no gcd possible.
    } else {
        long long gcd = k - n/2 + 1;
        cout << gcd << " " << gcd * 2 <<" ";
        int i = 1;
        for (int count = 3; count < n + 1; count++, i++) {
            if (i == gcd || i == 2*gcd) {
                //that number and even/odd number next to it.
                if (i % 2)
                    i += 2;
                else
                    i += 1;
            }
            cout << i << " ";
        }
    }
    return 0;
}
