// Couldn't do it.

#include<iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    // Could have simply retured M * N/2; but written out explaination

    if (N % 2 == 0) {    // if N is even
        // place horizontally cover whole grid
        // couldn't have done better so no other solution
        cout<< N * M/2; // actually N/2 blocks in each row for m rows
    } else if ( M % 2 == 0) {
        // Same place vertically now
        // Each column M/2 for N columns
        // completely filled couldn't have done better
        cout<< N * M/2;
    } else
        // N and M both odd. One tile in this case will be empty
        // Fill N-1 column horizonatally and M -1 blocks of last column vertically
        cout<< N * M /2;     // More like (N - 1)/2 * M + (M-1)/2 = NM/2 - 1/2 = floor(NM/2) as N and M are odd
    return 0;

}
