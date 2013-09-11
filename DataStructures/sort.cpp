#include<string.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
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

enum HEAPDS { ARRAY, TREE };

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

        void printArray(int start, int end) {
            printArray(arr, start, end);
        }
        void printArray() {
            printArray(arr, 0, length - 1);
        }

        void printArray(int *array, int start, int end) {
            printArray(NULL, array, start, end);
        }
        void printArray(char* label, int *array, int start, int end) {
            int i = start;
            if (label != NULL)
                write(label);
            while (i <= end) {
                write(array[i++]);
            }
            write("\n");
        }

};

class InsertionSort : public Sort {
    public:
        InsertionSort(int *a, int len) : Sort(a, len) {
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
        }
};


class MergeSort: public Sort {
    public:
        MergeSort(int *a, int len) : Sort(a, len) {
            temp = new int [length];
        }

        virtual void execute() {
            divideRoutine(0, length - 1);
        }
    private:
        int *temp;
        void divideRoutine(int start, int end) {
            if (start < end) {
                int middle = (start + end)/2;
                divideRoutine(start, middle);
                divideRoutine(middle + 1, end);
                mergeRoutine(start, middle, end);
            }
        }
        void mergeRoutine(int start, int middle, int end) {
            int i = 0, l=start, r = middle + 1;
            while (middle >= l && end >= r) {
                if (arr[l] < arr[r]) {
                    temp[i] = arr[l];
                    l++;
                } else {
                    temp[i] = arr[r];
                    r++;
                }
                i++;
            }

            while (l <= middle) {
                temp[i++] = arr[l++];
            }

            while (r <= end) {
                temp[i++] = arr[r++];
            }
            for (int j = start, k = 0; j <= end; j++, k++)
                arr[j] = temp[k];
        }

};

class QuickSort : public Sort {
    public:
        QuickSort(int *a, int len) : Sort(a, len) {
            // init seed to choose pivot randomly.
            srand(time(0));
        }
        virtual void execute() {
            quickSortRoutine(0, length - 1);
        }
    private:
        int pivot;

        void quickSortRoutine(int start, int end) {
            if (start < end) {
                int pivot = start + rand() % (end - start);
                swap(arr[start], arr[pivot]);
                int i = start + 1, j = end;
                while (i <= j) {
                    if (arr[i] < arr[start]) {
                        i++;
                    } else {
                        swap(arr[i], arr[j]);
                        j--;
                    }
                }
                swap(arr[start], arr[i - 1]);
                quickSortRoutine(start, i - 2);
                quickSortRoutine(i, end);
            }
        }
        void swap(int& a, int& b) {
            int c = b; b = a;a = c;
        }
};
class HeapSort: public Sort {
    public:
        HeapSort(int *a, int len, HEAPDS ds):Sort(a, len) {
        }
        HeapSort(int *a, int len) : Sort(a, len) {
            dsType = TREE;
        }
    private:
        HEAPDS dsType;
};

int main() {
    int len, i=0;
    cin>>len;
    int *a = new int[len];
    while(len > i) {
        cin>>a[i];
        i++;
    }
    //Sort *sort = new InsertionSort(a, len);
    //Sort *sort = new MergeSort(a, len);
    Sort *sort = new QuickSort(a, len);
    sort->execute();
    if (DEBUG)
        sort->printArray();
    return 0;
}
