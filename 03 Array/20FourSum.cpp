#include<bits/stdc++.h>
using namespace std;


// Brute Force

// vector<vector<int>> FourSum(vector<int> &num, int target){
//     int n = num.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             for (int k = 0; k < n; k++)
//             {
//                 for (int l = k+1; l < n; l++)
//                 {
//                     long long sum = num[i] + num[j];
//                     sum += num[k];
//                     sum += num[l];
//                     if(sum == target){
//                         vector<int> v = {num[i], num[j], num[k], num[l]};
//                         sort(v.begin(), v.end());
//                         st.insert(v);
//                     }
//                 }
//             }            
//         }        
//     }            
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }


// Better Approach

// vector<vector<int>> FourSum(vector<int> &num, int target){
//     int n = num.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             set<int> hashset;
//             for (int k= j+1; k < n; k++)
//             {
//                 hashset.insert(num[k]);
//                 long long sum = num[i] + num[j];
//                 sum += num[k];
//                 long long Fourth = target - sum;
//                 if(hashset.find(Fourth) != hashset.end()){
//                     vector<int> temp = {num[i], num[j], num[k], (int)(Fourth)};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);                         
//                 }
//                 hashset.insert(num[k]);
//             }
//         }   
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }


// Optimal Approach

vector<vector<int>> FourSum(vector<int> &num, int target){
    int n = num.size();
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        if (i>0 && num[i]==num[i-1])
        {
            continue;
        }                
        for (int j = i+1; j < n; j++)
        {
            if (j > i + 1 && num[j] == num[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = num[i];
                sum += num[j];
                sum += num[k];
                sum += num[l];
                if (sum == target)
                {
                    vector<int> temp = {num[i], num[j], num[k], num[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    // skip the duplicates:
                    while (k < l && num[k] == num[k - 1])
                        k++;
                    while (k < l && num[l] == num[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
}


int main(){
    int n;
    cout << "Enter the value of n" << endl;
    cin>>n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    int target;
    cout << "Enter the value of target" << endl;
    cin>>target;
    vector<vector<int>> ans = FourSum(num, target);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}