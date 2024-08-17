#include<bits/stdc++.h>
using namespace std;

// Brute Force approach

// vector <vector<int>> RotateMatrix(vector<vector<int>> &matrix){
//     int n = matrix.size();
//     vector<vector<int>> ans(n, vector <int>(n,0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ans[j][n - i - 1] = matrix[i][j];
//         }        
//     }
//     return ans;
// }

// Optimal approach

vector <vector<int>> RotateMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    
    // First we do transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);            
        }        
    }

    // Then we reverse the rows
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }    
    return matrix;
}


int main()
{
    int n;
    cout << "Enter the size of matrix : ";
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n,0));
    cout<<"Enter the elements of the matrix : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }        
    }
    vector<vector<int>> ans = RotateMatrix(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }        
        cout<<endl;
    }
    return 0;    
}