#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is odd or even
bool isOdd(int n)
{
    return (n & 1) == 1; // If the last bit is 1, the number is odd
}

// Function to get the kth bit
bool getKthBit(int n, int k)
{
    return (n & (1 << k)) != 0;
}

// Function to set the kth bit
int setKthBit(int n, int k)
{
    return n | (1 << k);
}

// Function to clear the kth bit
int clearKthBit(int n, int k)
{
    return n & ~(1 << k);
}

// Function to count the number of set bits
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

// Function to check if a number is a power of 2
bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

// Function to swap two numbers without using a temporary variable
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Function to find the only non-repeating element in an array
int findSingle(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    return result;
}

// Main function demonstrating all the above functionalities
int main()
{
    cout << "=== Bit Manipulation Techniques ===" << endl;

    // 1. Check if a number is odd or even
    int num = 7;
    cout << "1. Odd or Even: " << num << " is " << (isOdd(num) ? "Odd" : "Even") << endl;

    // 2. Get the kth bit
    int k = 1; // Zero-indexed
    cout << "2. Get " << k << "th Bit of " << num << ": " << (getKthBit(num, k) ? "Set" : "Not Set") << endl;

    // 3. Set the kth bit
    cout << "3. Set " << k << "th Bit of " << num << ": " << setKthBit(num, k) << endl;

    // 4. Clear the kth bit
    cout << "4. Clear " << k << "th Bit of " << num << ": " << clearKthBit(num, k) << endl;

    // 5. Count the number of set bits
    cout << "5. Count Set Bits in " << num << ": " << countSetBits(num) << endl;

    // 6. Check if a number is a power of 2
    int powerNum = 16;
    cout << "6. Is " << powerNum << " a Power of 2? " << (isPowerOfTwo(powerNum) ? "Yes" : "No") << endl;

    // 7. Swap two numbers without a temporary variable
    int a = 5, b = 3;
    cout << "7. Before Swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "   After Swap: a = " << a << ", b = " << b << endl;

    // 8. Find the single non-repeating element in an array
    int arr[] = {4, 3, 4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "8. Single Non-Repeating Element in Array: " << findSingle(arr, n) << endl;

    return 0;
}
