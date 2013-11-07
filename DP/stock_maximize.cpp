/*
 * https://www.hackerrank.com/challenges/stockmax
 * Your algorithms have become so good at predicting the market that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the next N days.
 *
 * Each day, you can either buy one share of WOT, sell any number of shares of WOT that you own or not make any transaction at all. What is the maximum profit you can obtain with an optimum trading strategy?
 *
 * Input
 *
 * The first line contains the number of test cases T. T test cases follow:
 *
 * The first line of each test case contains a number N. The next line contains N integers, denoting the predicted price of WOT shares for the next N days.
 *
 * Output
 *
 * Output T lines, containing the maximum profit which can be obtained for the corresponding test case.
 *
 * Constraints
 *
 * 1 <= T <= 10
 * 1 <= N <= 50000
 *
 * All share prices are between 1 and 100000
 *
 * Sample Input
 * 3
 * 3
 * 5 3 2
 * 3
 * 1 2 100
 * 4
 * 1 3 1 2
 *
 * Sample Output
 * 0
 * 197
 * 3
 *
 */


#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
/*
 * Approach:
 *  Keep accumulating stocks till you see largest stock price
 *  Sell all accumulated stocks till then and repeat this for other days
 *
 *  Approach here is bit smarter.
 *  Here we start from the back calling last day's price at maximum
 *  We look at previous days and in case the price that day was less,
 *  we say we bought the stock that day and sold at day of the maxium price
 *  Else if price is greater we call the new price as max price and carry on checking previous days.
 */
long maxProfit (int A[], int len) {
    long profit[len];
    //Base Case
    for (int i = 0; i < len; i++) {
        profit[i] = 0;
    }
    // If there is one day only share price would be max on that day only
    int max = A[len - 1];

    for (int i = len - 2; i >= 0; i--) {
        profit[i] = profit[i + 1];
        if (A[i] < max) {
            profit[i] += max - A[i];
        } else {
            max = A[i];
        }
    }
    return profit[0];
}

int main() {
    int T, N;
    cin >> T; // Number of test cases.
    while(T--) {
        cin >> N;
        int C[N]; // array to store cost of stock.
        for(int i = 0; i < N; i++) {
            cin >> C[i];
        }
        cout<<maxProfit(C, N)<<"\n";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

