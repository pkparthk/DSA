#include<bits/stdc++.h>
using namespace std;


// int trap(vector<int> &arr){
//     int n = arr.size();
//     int prefix[n], sufix[n];
//     prefix[0] = arr[0];    
//     for (int i = 1; i < n-1; i++)
//     {
//         prefix[i] = max(prefix[i - 1], arr[i]);
//     }
//     sufix[n-1] = arr[n-1];
//     for (int i = n-2; i > 0; i--)
//     {
//         sufix[i] = max(sufix[i + 1], arr[i]);
//     }
//     int water = 0;
//     for (int i = 0; i < n; i++)
//     {
//         water += min(prefix[i], sufix[i]) - arr[i];
//     }
//     return water;    
// }

// Time Complexity = O(3N);
// Space Complexity = O(N) + O(N);    


// Optimised Approach

int Trap(vector<int> &arr){
    int n = arr.size();
    int lMax = 0, rMax = 0;
    int total = 0;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (lMax <= arr[left])
            {
                lMax = arr[left];
            }
            else
            {
                total += lMax - arr[left];
            }
            left++;
        }
        else
        {
            if (rMax <= arr[right])
            {
                rMax = arr[right];
            }
            else
            {
                total += rMax - arr[right];
            }
            right--;
        }
    }
    return total;
}

// Time Complexity = O(N);
// Space Complexity = O(1);


int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // cout << "The water that can be trapped is " << trap(v) << endl;
    cout << "The water that can be trapped is " << Trap(v) << endl;
}   