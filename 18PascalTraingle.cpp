// Problem Statement : This problem has 3 variations.They are stated below :

//     Variation 1 : Given row number r and column number c.Print the element at position(r, c)
//     in Pascal’s triangle.

//     Variation 2 : Given the row number n.Print the n - th row of Pascal’s triangle.

//     Variation 3 : Given the number of rows n.Print the first n rows of Pascal’s triangle.

#include<bits/stdc++.h>
using namespace std;

// Variation 1

// USE :-  nCr = n ! / (r !*(n - r) !)

// int nCr(int n, int r){
//     int res = 1;
//     for(int i = 0; i < r; i++){
//         res *= (n - i);
//         res /= (i + 1);
//     }
//     return res;
// }

// int pascalTriangle(int r, int c)
// {
//     int element = nCr(r - 1, c - 1);
//     return element;
// }

// int main(){
//     int r, c;
//     cin >> r >> c;   // Row and Clolumn number
//     cout << pascalTriangle(r, c) << endl;
//     return 0;
// }


// Variation 2

// int nCr(int n, int r){
//     int res = 1;
//     for(int i = 0; i < r; i++){
//         res *= (n - i);
//         res /= (i + 1);
//     }
//     return res;
// }

// void pascalTriangle(int n)
// {
//     // Printing the entire row
//     for(int i = 0; i < n; i++){
//         cout << nCr(n - 1, i) << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int n;
//     cout << "Enter the value of row to print: " << endl;
//     cin >> n;   // Row number
//     pascalTriangle(n);
//     return 0;
// }


// Variation 3

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> generatePascalTriangle(int N)
{
    vector<vector<int>> ans;
    for (int i = 1; i<= N; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the number of rows to print: " << endl;
    cin >> n;   // Number of rows
    vector<vector<int>> ans = generatePascalTriangle(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}