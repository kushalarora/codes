#include<iostream>

using namespace std;

const long long MAX = 2000000;
long long fact_mod[MAX];

const long long mod = 1000000007;



int main() {
    fact_mod[0] = 1;
    for (long long i = 1; i < MAX; i++) {
        fact_mod[i] = (fact_mod[i - 1] * i);
        cout << fact_mod[i] << endl;
    }

    long long T, m, n;
    cin >> T;
    while(T--) {
        cin >> m >> n;
        cout << ((fact_mod[m + n - 2]/fact_mod[m - 1])/fact_mod[n - 1]) % mod << endl;
    }
}
