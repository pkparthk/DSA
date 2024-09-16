#include<bits/stdc++.h>
using namespace std;

// Better Approach

// vector<int> MissingAndRepeatingNo(vector<int> a){
//     int n = a.size();
//     int hash[n + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         hash[a[i]]++;    
//     }
//     int repeating =  -1, missing = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (hash[i]>=2)
//         {
//             repeating = i;
//         }
//         else if (hash[i]==0)
//         {
//             missing = i;
//         }
//         if (repeating != -1 && missing != -1)
//         {
//             break;
//         }           
//     }
//     return {repeating, missing};
// }


// Optimal Approach 1 : Maths

vector<int> MissingAndRepeatingNo(vector<int> a) {
    long long n = a.size();
    //  S - Sn = x - y
    // S2 - S2n x^2 - y^2
    long long Sn = n * (n + 1) / 2;
    long long S2n = n * (n + 1) * (2 * n + 1) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];        
    }
    long long val1 = S - Sn; // x - y
    long long val2 = S2 - S2n;
    val2 = val2 / val1; // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}


int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    vector<int> a(n);
    cout << "Enter the values of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans = MissingAndRepeatingNo(a);
    cout << "Repeating No: " << ans[0] << endl;
    cout << "Missing No: " << ans[1] << endl;
    return 0;
}