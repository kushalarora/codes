#include<iostream>

using namespace std;

inline int nAttackingMoves(int x, int y, int N, int M) {
    int moves = 0;
    // left down
    if (x >= 2 && y != M)
        moves++;
    // left up
    if (x >= 2 && y != 0)
        moves++;
    // right down
    if (x <= N - 2 && y != M)
        moves++;
    // right up
    if (x <= N - 2 && y != 0)
        moves++;
    // up left
    if (y >= 2 && x != 0)
        moves++;
    // up right
    if (y >= 2 && x != N)
        moves++;
    // down left
    if (y <= M - 2 && x != 0)
        moves++;
    // down right
    if (y <= M - 2 && x != N)
        moves++;
    return moves;
}

int main() {
    int T, M, N, i , j;
    long long moves;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        moves = 0;
        for (i = 0; i < M; i++)
            for (j = 0; j < N; j++)
                moves += nAttackingMoves(i, j, M - 1, N - 1);
        cout << M*N*(M*N - 1) - moves << endl;
    }
}
