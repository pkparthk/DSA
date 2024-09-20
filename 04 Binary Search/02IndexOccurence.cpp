#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid]>x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k){
    int lb = lowerBound(arr, n, k);
    if (lb==n || arr[lb]!=k)
    {
        return {-1, -1};
    }
    return {lb, upperBound(arr, n, k) - 1};
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
    sort(arr.begin(), arr.end());
    int x;
    cin >> x;    
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    cout << "First Occurence: " << ans.first << endl;
    cout << "Last Occurence: " << ans.second << endl;
    return 0;
}