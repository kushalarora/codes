#include<iostream>
#include<map>
using namespace std;

map<int, bool> repeated;

int main() {
    int n,m;
    cin >> n >> m;
    int a[n][m];

    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (repeated.find(a[i][j]) == repeated.end()) {
                repeated[a[i][j]] = false;
            } else {
                repeated[a[i][j]] = true;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (repeated[a[i][j]])
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }



    int max_area = 0, min_val;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 1)
                a[i][j] += a[i][j - 1]
        }
    }


    for (int j = 0; j < m; j++) {
        min_val = m;
        for (int i = 0; i < n; i++) {
            if (a[i][j] < min_val)
                min_val = a[i][j];

            if (min_val * (i + 1) > max_area)
                max_area = min_val * (i + 1);
        }
    }
}

