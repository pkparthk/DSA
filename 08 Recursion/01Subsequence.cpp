#include<bits/stdc++.h>
using namespace std;

void PrintF(int index, vector<int> &a, int arr[], int n)
{
    if (index == n){
        // for (int i = 0; i < n; i++)
        for(auto it: a)
        {
            cout << it << " ";
        }
        if (a.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // Take the element
    a.push_back(arr[index]);
    PrintF(index+1, a, arr, n);
    a.pop_back();

    // Don't take the element
    PrintF(index+1, a, arr, n);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> a;
    PrintF(0, a, arr, n);
    return 0;
}