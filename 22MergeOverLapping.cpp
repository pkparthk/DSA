#include<bits/stdc++.h>
using namespace std;

// Brute Force

// vector<vector<int>> MergeOverlapping(vector<vector<int>> &arr){
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> ans;
//     for (int i = 0; i < n; i++)
//     {
//         int start = arr[i][0];
//         int end = arr[i][1];
//         if (!ans.empty() && end<=ans.back()[1])
//         {
//             continue;
//         }
//         for (int j = i+1; j < n; j++)
//         {
//             if (arr[j][0]<=end)
//             {
//                 end = max(end, arr[j][1]);
//             }
//             else
//             {
//                 break;
//             }            
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
// }


//  Optimal Approach
vector<vector<int>> MergeOverlapping(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of arr" << endl;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    cout << "Enter the values of arr" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<vector<int>> ans = MergeOverlapping(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}