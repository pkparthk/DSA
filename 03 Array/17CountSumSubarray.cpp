#include<bits/stdc++.h>
using namespace std;

// Brute Force approach

// int countSumSubarray(vector<int> &arr, int sum)
// {
//     int n = arr.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int currSum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 currSum += arr[k];
//             }
//             if (currSum == sum)
//             {
//                 count++;
//             }
//         }        
//     }
//     return count;
// }
// Time Complexity: O(n^3)
// Space Complexity: O(1)



// Better approach

// int countSumSubarray(vector<int> &arr, int sum)
// {
//     int n = arr.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int currSum = 0;
//         for (int j = i; j < n; j++)
//         {
//             currSum += arr[j];
//             if (currSum == sum)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Time Complexity: O(n^2)
// Space Complexity: O(1)



// Optimal approach
// prefix sum concept

int countSumSubarray(vector<int> &arr, int sum)
{
    int n = arr.size();
    map<int, int> mpp;
    mpp[0] = 1;
    int count = 0;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        int remove = prefixSum - sum;
        count += mpp[remove];
        mpp[prefixSum]++;
    }
    return count;
}
// Time Complexity: O(n)
// Space Complexity: O(n)



int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cout << "Enter the sum : ";
    cin >> sum;
    cout << "The number of subarrays with sum equal to " << sum << " is " << countSumSubarray(arr, sum) << endl;
    return 0;
}