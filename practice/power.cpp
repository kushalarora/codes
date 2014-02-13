/*
 * Calculate power of function
 *  pow(x, y)
 *  y can be negative
 *  x can be negative
 *  y can be integer only
 *
 * Three smart approches
 * First O(n)
 * Second O(lgn)
 * Third supports negative
 */



/*
 * T(n) = T(n/2) + T(n/2) + 1;
 * O(n)
 */

#include<iostream>
using namespace std;
float pow1(float x, int y) {
    if (y == 0)
        return 1;
    else if (y % 2)
        return pow1(x, y/2) * pow1(x, y/2) * x;
    else
        return pow1(x, y/2) * pow1(x, y/2);
}

/*
 * T(n) = T(n/2) + 1
 */
float pow2(float x, int y) {
    float temp;
    if (y == 0)
        return 1;
    temp = pow2(x, y/2);
    if (y % 2)
        return temp * temp * x;
    else
        return temp * temp;
}

/*
 * Uses pow2 but supports negative values of y
 */

float pow3(float x, int y) {
    float temp;
    if (y == 0)
        return 1;
    temp = pow3(x, y/2);
    if (y % 2 == 0)
        return temp * temp;
    else {
        if (y > 0)
            return temp * temp * x;
        else
            return temp * temp/x;
    }
}


int main() {
    cout << pow1(3, 3) << endl;
    cout << pow2(3, 3) << endl;
    cout << pow3(3, 3) << endl;
    cout << pow3(2, -3) << endl;
}
