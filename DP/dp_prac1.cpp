/*
 *
 *  http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=dynProg
 *
 * Given a list of N coins, their values (V1, V2, ... , VN), and the total sum S.
 * Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want),
 * or report that it's not possible to select coins in such a way that they sum up to S.
 */


/*
 * Step 1:
 *  Figure out recursion that solves the problem.
 *  In many cases that have structure of combinatorial problem, all possibilities are to be verified.
 *
 * Step 2:
 *  Secondly figure out the dimension/entity which is limited in size, which can be stored in array.
 *  Formulate problem such that this dimension is a state or subproblem.
 *
 */

using namespace std;
#include<iostream>
#include <climits>
// Approach here is to traverse on number of coins.
// Look for all the sum that can be generated with x number of coins.
// Stop either when S is achieved or x number of coins all produce sum greater than S in which case return -1;
int my_solution(int a[], int a_size, int S) {

    // cache of size S. Stores number of coins need to generate numbers upto S.
    int c[S];
    int i;
    for (i = 0; i < S; i++) {
        // initializing cache to represent these number as of now are not reached.
        c[i] = -1;
    }

    for (i = 0; i < a_size; i++) {
        if (a[i] <= S)
            c[a[i] - 1] = 1;
    }

    bool all_greater_than_s = false;
    // generated all numbers that can be generated using j coins.
    int j = 1;
    int k;
    int num;
    // continue loop till all number generated in j coins pass
    // is greater than S.
    while(!all_greater_than_s) {

        // assuming this pass will generate all number greater than S.
        all_greater_than_s = true;

        // loop thru the cache
        for (i = 0; i < S; i++) {
            // look for numbers reached in last pass.
            if (c[i] == j) {
                // add all a[s] to each to generate j + 1 coin pass.
                for (k = 0; k < a_size; k++) {
                    num = i + 1 + a[k];

                    // This is the way to reach number in least passes.
                    if(num == S)
                        return c[i] + 1;
                    // discard number that are greater than S.
                    else if (num < S) {
                        all_greater_than_s = false;
                        // c[num] has never been reached or this is smallest combination to reach c[num]
                        // then update c[num]
                        int idx = num - 1;
                        if (c[idx] == -1 || c[idx] > c[i] + 1)
                            c[idx] = c[i] + 1;
                    }
                }
            }
        }
        j++;
    }

    return -1;
}

// this is based on recursion approach.
// C(X) = 1 + min(C(X-V1), C(X-V2), .... C(X-VN))
// Now the state of limited quantity here is C(X) i.e. min number of coins to X.
// Initialize all cost upto S by INT_MAX.
// Base case is 1 coin one.
// Calculate cost for each C(X) upto S untill S is reached.
// That will be minimum cost C for S.
int my_solution2(int a[], int a_size, int S) {
    int C[S + 1];
    int i;
    for (i = 0; i <= S; i++) {
        C[i] = INT_MAX;
    }

    for (i = 0; i < a_size; i++) {
        if (a[i] == S)
            return 1;
        else if (a[i] < S)
            C[a[i]] = 1;
    }
    int sum;
    for (i = 0; i <= S; i++) {
        for (int j = 0; j < a_size; j++) {
            if (C[i] == INT_MAX)
                continue;
            sum = i + a[j];
            if (sum == S) {
                return C[i] + 1;
            } else if (sum < S) {
                if (C[sum] > C[i] + 1)
                    C[sum] = C[i] + 1;
            }
        }
    }
    if (C[S] != INT_MAX)
        return C[S];
    return -1;
}

int main() {
    int N, S;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> S;
    int out = my_solution2(a, N, S);
    if (out == -1)
        cout << "Total "<< S <<" cannot be reached" << "\n";
    else
        cout << "We need at least " << out << " coins to generate "<< S << "\n";
    return 0;
}
