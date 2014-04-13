#include<iostream>

using namespace std;

int dp[2001][2001] = {0};
int MOD = 1000000007;
int main() {
    int k, n;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        // There are N possibility for length 1 sequence, each from 1 to N.
        dp[0][i] = 1;

    // from length 2 onwards, for sequence of length i + 1 starting with j + 1(0 + 1)
    // total possibilities are total number of i sequence ending at m such that m is divisor of j.
    for (int i = 1; i < k; i++)
        for (int j = 0; j < n; j++)
            // for all the numbers that are multiple of j, add J entries.
            for (int m = j; m < n; m += j)
                dp[i][m] = (dp[i][m] + dp[i - 1][j]) % MOD;

     int sum = 0;
     for (int i = 1; i <= n; i++)
         sum = (sum + dp[k][i]) % MOD;
     cout << sum << endl;
     return 0;
}
