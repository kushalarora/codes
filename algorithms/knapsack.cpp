#include<iostream>

using namespace std;

long knapsack(int idx, int N, int wght_lft, int Arr[][2], long val_tl_now) {
    cout << "idx: " << idx << " wght_left: " << wght_lft << " val till now: " << val_tl_now << endl;
    if (idx == N ||     // reached end, max possible wieght
            wght_lft < Arr[idx][1])     // filled to capacity, cannot add current item
        return val_tl_now;
    // There is space go further down the options to what can be added to current pile.
    // Return maximum possible value of subtree.
    return  max(knapsack(idx + 1, N, wght_lft - Arr[idx][1], Arr, val_tl_now + Arr[idx][0]),    // Try with current item
                knapsack(idx + 1, N, wght_lft, Arr, val_tl_now));   // Try without current item.
}

int main() {
    int Arr[3][2] = {{60, 20}, {100, 30}, {120, 30}};

    int W = 10;

    cout << knapsack(0, 3, W, Arr, 0);
}
