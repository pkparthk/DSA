#include<bits/stdc++.h>
using namespace std;

// Brute Force

// vector<vector<int>> triplet(int n, vector<int> &num){
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {           
//         for (int j = i+1 ; j < n; j++)
//         {
//             for (int k = j+1; k < n; k++)
//             {
//                 if(num[i] + num[j] + num[k] == 0){
//                     vector<int> v = {num[i], num[j], num[k]};
//                     sort(v.begin(), v.end());
//                     st.insert(v);    
//                 }
//             }            
//         }        
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }


// Beeter Approach

// vector<vector<int>> triplet(int n, vector<int> &num){
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashset;
//         for (int j = i+1; j < n; j++)
//         {
//             int third = -(num[i] + num[j]);
//             if(hashset.find(third) != hashset.end()){
//                 vector<int> v = {num[i], num[j], third};
//                 sort(v.begin(), v.end());
//                 st.insert(v);
//             }
//             else{
//                 hashset.insert(num[j]);
//             }
//         }        
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }


// Optimal Approach

vector<vector<int>> triplet(int n, vector<int> &num){
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        if (i>0 && num[i]==num[i-1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j<k) 
        {
            int sum = num[i] + num[j] + num[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum>0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {num[i], num[j], num[k]};                
                ans.push_back(temp);
                j++;
                k--;
                while (j<k && num[j]==num[j-1])
                {
                    j++;
                }
                while (j<k && num[k]==num[k+1])
                {
                    k--;
                }                
            }                        
        }        
    }
    return ans;
}


int main(){
    int n;
    cout << "Enter the number elements in array";
    cin >> n;
    vector<int> num(n);
    cout << "Enter the elements in array";
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    vector<vector<int>> ans = triplet(n, num);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}