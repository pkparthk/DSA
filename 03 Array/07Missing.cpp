#include<bits/stdc++.h>
using namespace std;


//By Hashset Method

int findMissingNumber(int arr[], int n)
{
    unordered_set<int> hashSet;

    // Add all elements of array to hashset
    for (int i = 0; i < n - 1; i++)
    {
        hashSet.insert(arr[i]);
    }

    // Check each integer from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // If integer is not in hashset, it is the missing integer
        if (hashSet.find(i) == hashSet.end())
        {
            return i;
        }
    }

    // If no integer is missing, return n+1
    return n + 1;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, n);
    cout << "Missing number is: " << missingNumber << endl;

    return 0;
}


// By Sum Method

// #include <bits/stdc++.h>
// using namespace std;

// int missingNumber(int n, vector<int> &arr)
// {
//     int sum = 0;
//     // Calculate the sum of array elements
//     for (int i = 0; i < n - 1; i++)
//     {
//         sum += arr[i];
//     }

//     // Calculate the expected sum
//     int expectedSum = (n * (n + 1)) / 2;

//     // Return the missing number
//     return expectedSum - sum;
// }

// // Driver code
// int main()
// {
//     vector<int> arr = {1, 2, 3, 5};
//     int n = 5;
//     cout << missingNumber(n, arr);
//     return 0;
// }



// By XOR Method

// #include <bits/stdc++.h>
// using namespace std;
//
// int missingNumber(int n, vector<int> &arr)
// {
//     int xor1 = 0, xor2 = 0;

//     // XOR all array elements
//     for (int i = 0; i < n - 1; i++)
//     {
//         xor2 ^= arr[i];
//     }

//     // XOR all numbers from 1 to n
//     for (int i = 1; i <= n; i++)
//     {
//         xor1 ^= i;
//     }

//     // Missing number is the XOR of xor1 and xor2
//     return xor1 ^ xor2;
// }
// int main()
// {
//     vector<int> arr = {1, 2, 3, 5};
//     int n = 5;

//     // Function call
//     int miss = missingNumber(n, arr);
//     cout << miss;
//     return 0;
// }



// By Binary Search Method

// #include <iostream>
// using namespace std;

// int search(int ar[], int size)
// {
//     // Extreme cases
//     if (ar[0] != 1)
//         return 1;
//     if (ar[size - 1] != (size + 1))
//         return size + 1;

//     int a = 0, b = size - 1;
//     int mid;
//     while ((b - a) > 1)
//     {
//         mid = (a + b) / 2;
//         if ((ar[a] - a) != (ar[mid] - mid))
//             b = mid;
//         else if ((ar[b] - b) != (ar[mid] - mid))
//             a = mid;
//     }
//     return (ar[a] + 1);
// }

// int main()
// {
//     int ar[] = {1, 2, 3, 4, 5, 6, 8};
//     int size = sizeof(ar) / sizeof(ar[0]);
//     cout << "Missing number:" << search(ar, size);
// }