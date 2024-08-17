#include<bits/stdc++.h>
using namespace std;


// Brute force method
// void markRow(vector<vector<int>> &matrix, int n, int m, int i){
//     for (int j = 0; j < m; j++)
//     {
//         if (matrix[i][j]!=0)
//         {
//             matrix[i][j] = -1;
//         }        
//     }    
// }

// void markCol(vector<vector<int>> &matrix, int n, int m, int j){
//     for (int i = 0; i < n; i++)
//     {
//         if (matrix[i][j]!=0)
//         {
//             matrix[i][j] = -1;
//         }        
//     }    
// }

// vector<vector<int>> ZeroMatrix(vector<vector<int>> &matrix, int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 markRow(matrix, n, m, i);
//                 markCol(matrix, n, m, j);
//             }            
//         }        
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j]== -1)
//             {
//                 matrix[i][j] = 0;
//             }            
//         }        
//     }
//     return matrix;
// }



// Optimal Approach

vector<vector<int>> ZeroMatrix(vector<vector<int>> &matrix, int n, int m){
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j]==0)
            {
                // i-th Row
                matrix[i][0] = 0;
                if (j!=0)
                {
                    // j-th Column
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }            
        }        
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] !=0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }            
        }        
    }
    if (matrix[0][0]==0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }        
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }        
    }        
    return matrix;
}


int main()
{
    vector<vector<int>> matrix;
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
    vector<vector<int>> ans = ZeroMatrix(matrix, n, m);
    cout << "The Zero Matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}