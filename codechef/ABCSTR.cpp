#include<iostream>
#include<string>
#include<map>
using namespace std;


map<pair<int, int>, int> mp;
int main() {
    string str;
    cin >> str;

    int arr[3] = {0, 0, 0};
    // max 100000
    int size = str.length();
    long long total = 0;
    mp[make_pair(0,0)] = 1;
    for (int i = 0; i < size; i++) {
        arr[str[i] - 'A']++;
        pair<int, int> p = make_pair(arr[0] - arr[1], arr[0] - arr[2]);

        if (mp.find(p) == mp.end()) {
            mp[p] = 1;
        } else {
            total += mp[p];
            mp[p]++;
        }
    }

    cout << total <<endl;
}
