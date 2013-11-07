/*
 * Problem statement is to find out binomial coeff of (n,k) which gives number of ways k items can be choosen from n items.
 * This is basic for all combinatrial algorithms.
 * C(n,r) = n!/(n-k)!k! is a stupid way of calculating C(n,r).
 * Firstly there will mostly be overflow coz of factorial's involvement.
 * Secondly there is no need of this much computation.
 *
 * Better approach is to use Pascal Triangle
 *
 *                  1
 *              1       1
 *          1       2       1
 *      1       3       3       1
 *  1       4       6       4       1
 *
 *  The recurrence relation is C(n,k) = C(n-1, k-1) + C(n-1,k)
 *
 *  Base condition for recurrence.
 *   C(n-1, k-1) ---> C(n-k, 0) = 1
 *   C(n -1, k) ----> C(k,k) = 1
 *
 */

#include<iostream>
#include "../cpp/utils.hpp"
using namespace std;
const int MAXN = 100;

long long binomial_coeff(int n, int k) {
    long long map[MAXN][MAXN];
    int i,j;
    // init c(k, 0) = 1: Base case 1
    for(i = 0; i <=n; i++)
        map[i][0] = 1;

    // init c(k,k) = 1: Base case 2
    for (j = 0; j < n; j++)
        map[j][j] = 1;

    debug2(map[0][0], "");
    for (i = 1; i <= n; i++) {
        debug(map[i][0]);
        for(j = 1; j < i; j++) {
            map[i][j] = map[i - 1][j - 1] + map[i - 1][j];
            debug(map[i][j]);
        }
        debug2(map[i][j],"");
    }
    return (map[n][k]);
}

int main(int argc, char** argv) {
    int n, k;
    cin>>n>>k;
    cout<<binomial_coeff(n, k)<<"\n";
}
