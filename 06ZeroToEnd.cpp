// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;

// void moveZeroes(int arr[], int n)
// {
//     int index = 0;

//     // Move all non-zero elements to the beginning of the array
//     for (int i = 0; i < n; ++i)
//     {
//         if (arr[i] != 0)
//         {
//             arr[index++] = arr[i];
//         }
//     }

//     // Fill the remaining array positions with zeros
//     while (index < n)
//     {
//         arr[index++] = 0;
//     }

//     // Print the result
//     for (int i = 0; i < n; ++i)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     moveZeroes(arr, n);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
vector <int> moveZero(int n, vector <int> a){
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i]!=0)
        {
            temp.push_back(a[i]);
        }
    }
    int nZ = temp.size();
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    for (int i = nZ; i < n; i++)
    {
        a[i] = 0;
    }
    return a;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> res = moveZero(n, a);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}