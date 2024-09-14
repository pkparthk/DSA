#include<bits/stdc++.h>
using namespace std;

// Brute Force
int subArrayWithXOR(vector<int> arr, int k){
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int XOR = 0;
            for (int k = i; k <= j; k++){
                XOR = XOR ^ arr[k];                
            }
            if(XOR == k){
                count++;
            }
        }        
    }
    return count;
}

int main(){
    int n;
    cout << "Enter the value of n" << endl;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cout << "Enter the value of k" << endl;
    cin>>k;
    cout << subArrayWithXOR(arr, k) << endl;
    return 0;
}