#include <iostream>

using namespace std;

int reverseBits(unsigned int num) {
    int result = 0;
    int i = 0;
    while(num > 0) {
        result = ((result << 1) + (num & 1));
        num = num >> 1;
        i++;
    }
    return result;
}

int main() {
    unsigned int num;
    cin >> num;
    cout << reverseBits(num);
    return 0;
}
