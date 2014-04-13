#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int main() {
    int n, m, i = 0;
    cin >> n >> m;

    int a[m];
    while (i < m) {
        cin >> a[i++];
    }

    sort(a, a + m);
    int diff = INT_MAX;
    for (i = 0; i < m - n + 1; i+=1)
        if ((a[i + n - 1] - a[i]) < diff) {
            diff = a[i + n - 1] - a[i];
        }

    cout << diff << endl;
}
