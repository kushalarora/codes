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


int main() {
    int N, S;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> S;
    int out = my_solution(a, N, S);
    if (out == -1)
        cout << "Total "<< S <<" cannot be reached" << "\n";
    else
        cout << "We need at least " << out << " coins to generate "<< S << "\n";
    return 0;
}
