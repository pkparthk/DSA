#include<bits/stdc++.h>
using namespace std;

// Brute Force
// void merge(long long arr1[], long long arr2[], int n, int m){
//     long long arr3[n + m];
//     int left = 0;
//     int right = 0;
//     int index = 0;
//     while (left<n && right<m)
//     {
//         if (arr1[left]<=arr2[right])
//         {
//             arr3[index] = arr1[left];
//             left++, index++;
//         }
//         else
//         {
//             arr3[index] = arr2[right];
//             right++, index++;
//         }        
//     }
//     while (left<n)
//     {
//         arr3[index] = arr1[left];
//         left++, index++;
//     }
//     while (right<m)
//     {
//         arr3[index] = arr2[right];
//         right++, index++;
//     }
//     for (int i = 0; i < n+m; i++)
//     {
//         if (i<n)
//         {
//             arr1[i] = arr3[i];
//         }
//         else
//         {
//             arr2[i - n] = arr3[i];
//         }        
//     }
// }


// Optimal Approach 1

// void merge(long long arr1[], long long arr2[], int n, int m){
//     int left = n - 1;
//     int right = 0;
//     while (left>=0 && right<m)
//     {
//         if(arr1[left]>arr2[right]){
//             swap(arr1[left], arr2[right]);
//             left--;
//             right++;
//         }
//         else{
//             break;
//         }
//     }
//     sort(arr1, arr1+n);
//     sort(arr2, arr2 + m);
// }


// Optimal Approach 2
// Gap Method

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
    if (arr1[ind1]>arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }    
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        while (left + gap < len)
        {
            int right = left + gap;

            if (left < n && right >= n)
            {
                // left in arr1 and right in arr2
                swapIfGreater(arr1, arr2, left, right - n);
            }
            else if (left >= n)
            {
                // Both indices are in arr2
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            else
            {
                // Both indices are in arr1
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }

        if (gap == 1)
        {
            break; // If gap is 1, we can stop as this is the final pass
        }
        else
        {
            gap = (gap / 2) + (gap % 2); // Reduce gap for next iteration
        }    
    }
}

int main()
{
    int n, m;
    cout << "Enter the size of arr1" << endl;
    cin >> n;
    cout << "Enter the size of arr2" << endl;
    cin >> m;
    long long arr1[n], arr2[m];
    cout << "Enter the values of arr1" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the values of arr2" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    merge(arr1, arr2, n, m);
    cout << "The merged array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
