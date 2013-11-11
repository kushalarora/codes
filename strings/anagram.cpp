/*
 * https://www.hackerrank.com/challenges/anagram
 *
 * Given a string make left part an anagram of right part.
 * Determine minimum number of changes needed for this.
 * Look at problem statement for more details
 *
 * Sample Input
 *
 * 5
 * aaabbb
 * ab
 * abc
 * mnop
 * xyyx
 *
 * Sample Output
 * 3
 * 1
 * -1
 * 2
 * 0
 *
 * Approach:
 * Split string into two.
 * If odd length obviously left can't be anagram of right
 * Using bucketing approach.
 * Count each char for left part ie increment count for appearence of each char in an array
 * Match using right subpart and find out what number of chars in left substring is unaccounted for
 * As the length of left and right are same these unaccounted number of chars needs to be changed.
 */

#include<iostream>
#include<string>
using namespace std;


int main() {
    int T, len, i;
    int a[256];
    string str;
    cin>>T;
    while(T--) {
        for (i = 0; i < 256; i++) {
            a[i] = 0;
        }

        cin >> str;
        if (str.length() % 2 > 0) {
            cout << -1<<"\n";
            continue;
        }

        len = str.length() / 2;

        for (i = 0; i < len; i++) {
            a[str[i]]++;
        }

        for (i = 0; i < len; i++) {
            char c = str[i + len];
            if (a[c] > 0) {
                a[c]--;
            }
        }
        int count = 0;
        for (i = 0; i < 256 ; i++) {
            count += a[i];
        }
        cout << count<<"\n";
    }
}
