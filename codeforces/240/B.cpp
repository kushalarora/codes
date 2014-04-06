#include<iostream>
using namespace std;

int main() {
    int n;
    long long a, b, x;
    cin >> n >> a >> b;

    while(n--) {
        cin >> x;
        cout << ((x % b) * (a % b)) % b/a << " ";
    }
    return 0;
}
