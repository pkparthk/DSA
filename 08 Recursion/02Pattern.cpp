#include<bits/stdc++.h>
using namespace std;

// Pinnt all the subsets whose sum is equal to s

// void PrintS(int index, vector<int> &a, int s, int sum, int arr[], int n){
//     if (index == n){
//         if (sum == s){
//             for(auto it: a){
//                 cout << it << " ";                
//             }
//             cout << endl;            
//         }
//         return;
//     }

//     // Take the element
//     a.push_back(arr[index]);
//     s += arr[index];

//     PrintS(index+1, a, s, sum, arr, n);

//     s -= arr[index];
//     a.pop_back();

//     // Don't take the element   
//     PrintS(index+1, a, s, sum, arr, n);
// }


// Print only One Subset

bool PrintS(int index, vector<int> &a, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        if (sum == s)
        {
            for (auto it : a)
            {
                cout << it << " ";

            }
            cout << endl;
            return true;
        }
        else{
            return false;
        }
    }

    // Take the element
    a.push_back(arr[index]);
    s += arr[index];

    if(PrintS(index + 1, a, s, sum, arr, n) == true){
        return true;
    }

    s -= arr[index];
    a.pop_back();

    // Don't take the element
    if (PrintS(index + 1, a, s, sum, arr, n) == true){
        return true;
    }

    return false;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    vector<int> a;
    PrintS(0, a, 0, sum, arr, n);
    return 0;    
}