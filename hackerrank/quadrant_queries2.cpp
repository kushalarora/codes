#include<iostream>
#include<cassert>
#include<string>
using namespace std;

struct Node {
    int start;
    int end;
    int quad[4];
    Node* l_child;
    Node* r_child;
};

int refX[4] = {4, 3, 2, 1};
int refY[4] = {2, 1, 4, 3};
void reflectX(int arr[], int i, int j) {
    for(int k = i; k <= j; k++) {
        arr[k] = refX[arr[k] - 1];
    }

}
void reflectY(int arr[], int i, int j) {
    for(int k = i; k <= j; k++) {
        arr[k] = refY[arr[k] - 1];
    }
}

int getQuad(int x, int y) {
    return (x > 0 && y > 0 ? 1 :
            (x < 0 && y > 0 ? 2 :
             (x < 0 && y < 0 ? 3 : 4)));
}

void print4Quant(int arr[], int i, int j) {
    int Q[4] = {0, 0, 0, 0};
    for(int k = i; k <= j; k++) {
        Q[arr[k] - 1]++;
    }

    cout << Q[0] << " " <<Q[1] << " " << Q[2] << " " << Q[3] <<endl;
}

int main() {
    int N, x, y, Q, q_type, i, j, k=0;
    char query;
    cin >> N;
    int arr[N];
    // init sequence
    while(N--) {
        cin >> x >> y;
        arr[k++] = getQuad(x, y);
    }
    cin >> Q;
    while(Q--) {
        cin >> query >> i >> j;
        i -= 1;
        j -= 1;
        q_type = query == 'X' ? 0 : (query == 'Y' ? 1 : 2);
        switch(q_type) {
            case 0: {
                        reflectX(arr, i, j);
                        break;
                    }
            case 1: {
                        reflectY(arr, i, j);
                        break;
                    }
            case 2: {
                        print4Quant(arr, i, j);
                        break;
                    }
        }
    }
    return 0;
}
