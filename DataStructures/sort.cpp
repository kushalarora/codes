#include<string.h>
#include<iostream>
#include<string>
#include<math.h>
#include<map>
using namespace std;
#define DEBUG 1
#define REP(i, B, E) for(i = B; i < E; i++)
#define write(a) if (DEBUG) cout<<a<<" "
#define write2(a, b) if (DEBUG) cout<<a<<" "<<b<<"\n"
#define RESET_MEM(pointer, size) memset(pointer, 0, size)
#define ASCII_A 65
#define ASCII_Z 91
#define ASCII_a 97
#define ASCII_z 122
#define MAX 10000

class Sort {
    protected:
        int *arr;
        int length;
    public:
        Sort(int *a, int len) {
            arr = a;
            length = len;
        }
        virtual void execute(){}

        void printArray() {
            int i = 0;
            while (i < length) {
                write(arr[i]);
                i++;
            }
        }

};

class InsertionSort : public Sort {
    public:
        InsertionSort(int *a, int len) : Sort(a, len){
        }
        virtual void execute() {
            int i, j;
            for (i = 1; i < length; i++) {
                int key = arr[i];
                for (j = i - 1; j >= 0; j--) {
                    if (arr[j] > key) {
                        arr[j + 1] = arr[j];
                    } else {
                        break;
                    }
                }
                arr[j + 1] = key;
            }
            if (DEBUG)
                printArray();
        }
};
int main() {
    int len, i=0;
    cin>>len;
    int *a = new int[len];
    while(len > i) {
        cin>>a[i];
        i++;
    }
    Sort *sort = new InsertionSort(a, len);
    sort->execute();
    return 0;
}
