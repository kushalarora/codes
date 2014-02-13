#include<iostream>
using namespace std;

int main() {
    long long n,m,a,l,b;
    cin >> n >>m>>a;

    l = n/a + (n % a ? 1 : 0);
    b = m/a + (m % a ? 1 : 0);

    cout << (l * b);
    return 0;
}
