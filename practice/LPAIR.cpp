/*
 * http://www.codechef.com/problems/LPAIR
 */


#include<iostream>  // std::cout
#include<utility>   // std::pair, std::make_pair
#include<vector>
#include<algorithm>


using namespace std;


long long getIntersections(pair<int, int> arr[], int len) {
    long long result = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (arr[j].second < arr[i].second) {
                result++;
            }
        }
    }

    return result;
}

/*
 * As is visible from optimal substructure,
 * the problem needs a divide and conquer solution.
 *
 *
 *  So the interesting aspect is how to divide.
 *  Supposedly the problem is similar to counting inversions.
 *  Let for ith male, A[i] be the index of female he married.
 *
 *  Now the intersection will happen if
 *      A[i] > A[j] i < j
 *
 *  This statement is same as inversion counting.
 *
 *  The solution is extended merge sort, why
 *  Count inversion on left side, count inversion of right side of divide
 *  Now we have to count overlapping inversion.
 *  Inversion such that i in left side of divide and j on right side of divide
 *  and A[i] > A[j]
 *
 *  Now counting this overlapping solution will be O(n), but if we sort the array
 *  then this can be done in O(n) and count while merging.
 *
 */

long long merge(pair<int, int> vec[], int start, int middle, int end) {
    pair<int, int> scratch[end - start + 1];
    int i = start, j = middle + 1, k = 0;
    long long inversions = 0;
    while (i <= middle &&
            j <= end) {
        if (vec[i].second >= vec[j].second) {

            // because the array is sorted
            // all elements i to mid will be greater than j
            // so we need to count all these inversions
            inversions += middle - i + 1;

            scratch[k++] = vec[j++];
        } else {
            scratch[k++] = vec[i++];
        }
    }

    while (i <= middle)
        scratch[k++] = vec[i++];

    while(j <= end)
        scratch[k++] = vec[j++];

    for (int u = start; u <= end; u++)
        vec[u] = scratch[u];

    return inversions;
}

long long mergeSort(pair<int, int> vec[], int start, int end) {
    long long inversions = 0;
    if (start < end) {
        int middle = (start + end)/2;
        inversions += mergeSort(vec, start, middle);
        inversions += mergeSort(vec, middle + 1, end);

        inversions += merge(vec, start, middle, end);
    }
    return inversions;
}

long long countInversions(pair<int, int> vec[], int length) {
    return mergeSort(vec, 0, length - 1);
}

int main() {
    int T, male, female, i = 0;
    cin >> T;
    pair<int, int> vec[T];
    while(i < T) {
        cin >> male >> female;
        vec[i] = make_pair(male, female);
        i++;
    }
    sort(vec, vec + T);
    cout << countInversions(vec, T)<<endl;
    return 0;
}
