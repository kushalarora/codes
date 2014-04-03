#include<iostream>

using namespace std;

void matrixMultiplication(long long  M[2][2], long long N[2][2]) {
    int x = M[0][0] * N[0][0] + M[0][1] * N[1][0];
    int y = M[0][0] * N[0][1] + M[0][1] * N[1][0];
    int z = M[1][0] * N[0][0] + M[1][1] * N[1][0];
    int w = M[1][0] * N[0][1] + M[1][1] * N[1][0];

    M[0][0] = x; M[0][1] = y; M[1][0] = z; M[1][1] = w;
}


void matrixPower(long long M[2][2], int n) {
    if (n == 1 || n == 0)
        return;
    N[2][2] = {{1, 1}, {1, 0}};
    matrixPower(M, n>>1);

    if (n % 2)
        matrixMultiplication(M, N);
}

long long FibNew(int r1, int r2, int n) {
    int M[2][2] = { { 1, 1}, {1, 0}};
    matrixPower(M, n - 2);
    return r1 * M[0][0] + r2 * M[1][0];;
}

int main() {
    return 0;
}
