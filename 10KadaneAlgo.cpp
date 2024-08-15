#include <bits/stdc++.h>
using namespace std;


// Kadane's Algorithm 

// That is used for the to print only sum
// long long maxSubArraySum(vector<int> &arr, int n)
// {
//     long long maxSum = LONG_MIN, sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//         if (sum > maxSum)
//         {
//             maxSum = sum;
//         }
//         if (sum < 0)
//         {
//             sum = 0;
//         }
//         if (maxSum < 0)
//         {
//             maxSum = 0;
//         }
//     }
//     return maxSum;
// }

// That is used for to print tthe array
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The maximum subarray sum is: " << maxSubarraySum(arr, n) << endl;
    return 0;
}