#include<bits/stdc++.h>
using namespace std;

//BruteForce

// bool linearSearch(vector<int> &a, int num)
// {
//     int n = a.size(); // size of array
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] == num)
//         {
//             return true;
//         }            
//     }
//     return false;
// }
// int LCS(vector <int> &a){
//     int n = a.size();
//     int longest = 1;
//     for (int i = 0; i < n; i++)
//     {
//         int x = a[i];
//         int count = 1;
//         while (linearSearch(a, x+1) == true)
//         {
//             count++;
//             x++;
//         }
//         longest = max(longest, count);        
//     }
//     return longest;
// }



// Bette approach

// int LCS(vector<int> &a)
// {
//     int n = a.size();
//     if (n == 0)
//     {
//         return 0;
//     }
//     sort(a.begin(), a.end());
//     int lastSmaller = INT_MIN;
//     int longest = 1;
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] - 1 == lastSmaller)
//         {
//             count+=1;
//             lastSmaller = a[i];
//         }
//         else if (a[i] != lastSmaller)
//         {
//             count = 1;
//             lastSmaller = a[i];
//         }
//         longest = max(longest, count);
//     }
//     return longest;
// }



// Optimal approach

int LCS(vector<int> &a){
    int n = a.size();
    if (n == 0)
    {
        return 0;
    }
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (auto it: st){
        if (st.find(it-1)==st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x+1)!=st.end())
            {
                x = x + 1;
                count++;
            }
            longest = max(longest, count);
        }        
    }
    return longest;
}


int main()
{
    vector<int> a;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << "The length of the longest consecutive subsequence is: " << LCS(a);
    return 0;
}