#include<iostream>
using namespace std;

int main() {
    long long n;
    int s;
    long long count;
    cin >> n;
    long long arr[4] = {0, 0, 0 , 0};

    while (n--) {
        cin >> s;
        arr[s - 1]++;
    }

    // Accomodate one group of 4
    count = arr[3];

    // Accomodate group of 3;
    count += arr[2];

    arr[0] -= arr[2];

    // Accomodate two groups of 2;
    count += (arr[1] + 1)/2;

    if (arr[0] > 0) {
        arr[0] -= (arr[1] % 2) * 2;
    }

    // Accomodate group of 1
    if (arr[0] > 0) {
        count += arr[0]/4 + (arr[0] % 4 ? 1 : 0);
    }
    cout << count;
    return 0;
}
