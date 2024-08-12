#include <bits/stdc++.h>
using namespace std;

// Basic one

// string twoSum(int n, vector<int> &arr, int target)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == target)
//                 return "YES";
//         }
//     }
//     return "NO";
// }


// Optimized one
vector<int> twoSum(int n, vector<int> &arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}

int main()
{
    int n;
    cout << "Enter the number of element in array" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target sum" << endl;
    cin >> target;
    
    // FOR Variant 1: Basic 
    // string ans = twoSum(n, arr, target);
    // cout << "This is the answer for variant 1: " << ans << endl;

    // FOR Variant 2: Optimized
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: " << ans[0] << " " << ans[1] << endl;
    return 0;
}
