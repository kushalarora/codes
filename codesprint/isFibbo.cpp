#include<iostream>
#include<set>

const long long MAX = 10000000000;
using namespace std;

int main() {
    long long T, n1 = 0, n2 = 1, n;
    cin >> T;
    set<long long> s;
    s.insert(n1);
    //init
    while (n2 <= MAX) {
        s.insert(n2);
        long long tmp = n2;
        n2 = n1 + n2;
        n1 = tmp;
    }

    while(T--) {
        cin >> n;
        cout << (s.find(n) == s.end() ? "IsNotFibo" : "IsFibo") << endl;
    }
}
