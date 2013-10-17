/*
Dynamic Programming like Divide and Conquer solves problems by combining solutions to subproblem.
Divide and Conquer divides problem into independent problems, solve them recursively and combine them.
In contrast DP solves problem which are *Not independent*.
Dynamic Programming is used for solving optimization problems.
To get absolute optimum solution you need an exhaustive search but the cost of each of evaluating all outcomes in prohibitive.
Example is TSP. Tourist seek to visit all vertices at minimum total cost.

Dynamic programming is a way to design custom algorithms that systematically search all possibilities while storing results to avoid recomputing.

The approach should be design a correct recursive method and see if it can be speed up by storing partial results

Difference between dynamic programming and memozation is that dynamic programming is a left to right approach
Where as memoization is top down recursive approach with partial results stored.
Both give almost same asymptotic complexity just that dynamic programming approach is cleaner.


Example Fibbonacci
*/
#include<iostream>
#include<vector>

using namespace std;

// recursive approach.
// Calculates f[n-2] two times, f[n-3] three times and so on.
// Lot of redundant calculations which have been done before.
long fib_r(int n) {
    if(n == 0) return 0;
    if (n == 1) return 1;

    return (fib_r(n - 1) + fib_r(n - 2));
}



// This recursive approach can be bettered with memoization.
// Storing partial result in a global table and going ahead with recursion
// It will take O(n) space but will change this exponential time algorithm to linear time.

// Caching makes sense when space of distinct partial result is modest enough so that we can afford the cost of storage.
// Like in this case as the cost is between 0 to n i.e. O(n).

long f[1000];

const int UNKNOWN = -1;

long fib_mem(int n) {
    if (f[n] == UNKNOWN) {
        f[n] = fib_mem(n - 1) + fib_mem(n - 2);
    return f[n];
    }
}


long fib_mem_driver(int n) {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = UNKNOWN;

    return fib_mem(n);
}




// The solution with DP will have same asymptotic run time but without recursion and simpler implementation.
// It uses left to right approach of DP.
// Is considerably cleaner.

long fib_dp(int n) {
    long back2 = 0, back1 = 1;
    long next;

    if (n == 0) return 0;

    for (int i = 2; i < n; i++) {
        next = back1 + back2;
        back2 = back1;
        back1 = next;
    }
    return (back1 + back2);
}

int main(int argc, char** argv) {
    cout << "\n" << fib_r(40);
    cout<<"\n"<<fib_mem_driver(40);
    cout << "\n" << fib_dp(40);
}
