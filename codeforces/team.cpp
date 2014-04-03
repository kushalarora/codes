#include<iostream>
using namespace std;

int main() {
    int a,b,c, N, total = 0;
    cin >> N;
    while(N--) {
        cin >> a >> b >> c;
        if (a + b + c > 1)
            total+=1;
    }
    cout << total;
    return 0;
}
