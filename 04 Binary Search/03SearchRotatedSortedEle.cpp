#include<bits/stdc++.h>
using namespace std;

// int search(vector<int> &arr, int n, int target){
//     int low = 0;
//     int high = n-1;
//     while (low<=high)
//     {
//         int mid = (low + high) / 2;
//         if (arr[mid]==target)
//         {
//             return mid;
//         }
//         if (arr[low]<=arr[mid])   // left sorted
//         {
//             if (arr[low]<=target && target<=arr[mid])
//             {
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid + 1;
//             }
            
//         }
//         // right sorted
//         else{
//             if (arr[mid]<=target && target<=arr[high])
//             {
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }   
//     }
//     return -1;
// }



// When Array has Duplicates

int search(vector<int> &arr,int n, int target){
    int low = 0;
    int high = n-1;
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if (arr[mid]==target)
        {
            return mid;
        }
        if (arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low++;
            high--;
            continue;
        }
        else if (arr[low]<=arr[mid])   // left sorted
        {
            if (arr[low]<=target && target<=arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            
        }
        // right sorted
        else{
            if (arr[mid]<=target && target<=arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }   
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << search(arr, n, target) << endl;
    return 0;
}