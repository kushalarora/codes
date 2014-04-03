#include<iostream>
using namespace std;

// Simple. No explaination needed. Just use long long
//
//

int main() {
    int N, a, b;
    long long capacity = 0;
    long long passengers = 0;
    cin >> N;
    while (N--) {
        cin >> a >> b;
        passengers += (b - a);
        if (passengers > capacity) {
            capacity = passengers;
        }
    }
    cout << capacity;
    return 0;
}
