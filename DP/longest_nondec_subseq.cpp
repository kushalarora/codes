#include<iostream>
using namespace std;

/*
 * Given a sequence of N numbers - A[1] , A[2] , ..., A[N] . Find the length of the longest non-decreasing sequence.
 * http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=dynProg
 *
 * Definition of Longest Non-Decreasing SubSequence.
 * http://en.wikipedia.org/wiki/Longest_increasing_subsequence
 *
 * Test Case:
 * 8 7 1 9 3 2 6 4 5 10
 *
 * Output
 * 1 3 4 5 10
 * 5
 *
 *
 * These kind of problems what you need to do is let the longest length using DP.
 * BackTrack using additional saved info to get the sequence.
 * Similar to longest common subsequence from Algorithm Design Manual
 */

void printNonDecSubSeq(int s_idx, int p_idx[], int A[]) {
    if (s_idx > -1) {
        int prev_idx = p_idx[s_idx];
        printNonDecSubSeq(prev_idx, p_idx, A);
        cout<<A[s_idx]<<"\t";
    }
}

int longestNonDecSubSeq(int A[], int len) {
    // Array to DP. Stores length of longest subsequence uptill ith number.
    int ss_len[len];

    // Auxillary Array to store backtracking information.
    int prev_idx[len];

    int i,j;
    // Base case: Everyone's length is atleast one.
    // All of them doesn't have a previous number as the subseq contains only them.
    for (i = 0; i < len; i++) {
        ss_len[i] = 1;
        prev_idx[i] = -1;
    }

    // Tracks the length of element such that it is smaller than current
    // and has maximum subseq length till now.
    int prev_len;
    for (i = 1; i < len; i++) {
        prev_len = 0;
        for (j = 0; j  < i; j++) {
            if (A[j] <= A[i] &&     // j is smaller than i
                    ss_len[j] > prev_len) { // sub seq length of j is greater than current one.

                // set length of i as 1 greater than j
                ss_len[i] = 1 + ss_len[j];
                // set prev index of i as j for backtracking.
                prev_idx[i] = j;
                // update prev_len for further matching.
                prev_len = ss_len[j];
            }
        }
    }

    // figure out maximum value and index corresponding to that
    int max_idx = -1;
    int max_val = 0;
    for (i = len - 1; i >= 0; i--) {
        if (ss_len[i] > max_val) {
            max_val = ss_len[i];
            max_idx = i;
        }
    }
    // recursively print subseq
    printNonDecSubSeq(max_idx, prev_idx, A);
    cout<<"\n";
    return max_val;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout<<longestNonDecSubSeq(A, N);
    return 0;
}
