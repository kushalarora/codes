#include<iostream>

using namespace std;

inline int min3(int a,int b,int c) {
    return min(a, b) == a ? min(a, c) : min(b,c);
}
inline int max3(int a,int b,int c) {
    return max(a, b) == a ? max(a, c) : max(b, c);
}
int max_count(int n, int a, int b, int c, int count) {
    if ( n == 0)
        return count;

    if (n < min3(a,b,c))
        return 0;

    return max3(max_count(n - a, a, b, c, count + 1), max_count(n - b, a, b, c, count + 1), max_count(n - c, a, b, c, count + 1));
}

int main() {
    int n, a,b, c, count = 0;
    cin >> n >> a >> b >> c;
    int arr[n + 1];
    for (int i = 0; i < n + 1; i++)
        arr[i] = -1;
    arr[n] = 0;
    bool hit = false;
    do {
        hit = false;
        for (int i = n; i > 0; i--) {
            if (arr[i] == count) {
                hit = true;
                if (i - a >= 0) {
                    arr[i - a] = count + 1;
                }
                if (i - b >= 0) {
                    arr[i - b] = count + 1;
                }
                if (i - c >= 0) {
                    arr[i - c] = count + 1;
                }
            }
        }
        count += 1;
    } while (hit);
    cout << arr[0] << endl;
    return 0;


}
