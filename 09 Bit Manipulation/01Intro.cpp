#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 3;

    cout << "Basic Bitwise Operations:" << endl;
    cout << "AND (5 & 3): " << (a & b) << endl;           // Output: 1
    cout << "OR (5 | 3): " << (a | b) << endl;            // Output: 7
    cout << "XOR (5 ^ 3): " << (a ^ b) << endl;           // Output: 6
    cout << "NOT (~5): " << (~a) << endl;                 // Output: -6
    cout << "Left Shift (5 << 1): " << (a << 1) << endl;  // Output: 10
    cout << "Right Shift (5 >> 1): " << (a >> 1) << endl; // Output: 2

    return 0;
}
