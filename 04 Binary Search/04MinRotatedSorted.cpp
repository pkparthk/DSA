#include<bits/stdc++.h>
using namespace std;


// int findMin(vector<int> &arr){
//     int n = arr.size();
//     int low = 0;
//     int high = n-1;
//     int ans = INT_MAX;
//     while (low<=high)
//     {
//         int mid = (low + high) / 2;
//         if (arr[low]<=arr[mid])   // left sorted
//         {
//             ans = min(ans,arr[low]);
//             low = mid + 1;
//         }
//         // Right Sorted
//         else{
//             ans = min(ans,arr[mid]);
//             high = mid - 1;
//         }
//     }
// }   


// Optimised

int findMin(vector<int> &arr){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while (low<=high)
    {
        int mid = (low + high) / 2;        
        if (arr[low]<= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }
        if (arr[low]<=arr[mid])
        {
            ans = min(ans,arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans,arr[mid]);
            high = mid - 1;                                 
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<findMin(arr)<<endl;
    return 0;
}