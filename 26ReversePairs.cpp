#include<bits/stdc++.h>
using namespace std;

// Brute Force

int reversePairs(vector<int> &arr, int n){
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]>2*arr[j])
            {
                cnt++;        
            }            
        }
    }
    return cnt;
}

int team(vector<int> &skill, int n)
{
    return reversePairs(skill, n);
}


int main() 
{
    int n;
    cout << "Enter the number of elements : " << endl;
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "<< cnt << endl;
    return 0;
}