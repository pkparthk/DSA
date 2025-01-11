#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& res){
    if(ind == arr.size()){
        if(target == 0){
            res.push_back(ds);
        }
        return;
    }

    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ds, res);
        ds.pop_back();
    }

    findCombination(ind + 1, target, arr, ds, res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> ds;

    sort(candidates.begin(), candidates.end());

    findCombination(0, target, candidates, ds, res);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> res = combinationSum(arr, target);
    for (int  i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;        
    }
    
    return 0;
}