#include<iostream>
using namespace std;

int main() {
    int w;
    cin >> w;

    if (w < 4) {
        cout << "No";
        return 0;
    }

    cout << (w % 2 ? "No" : "Yes");
    return 0;
}
