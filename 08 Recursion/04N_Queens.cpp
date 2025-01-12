#include<bits/stdc++.h>
using namespace std;

// bool isSafe1(int row, int col, vector<string> &board, int n){
//     int dupRow = row;
//     int dupCol = col;

//     while (row >= 0 && col >= 0)
//     {
//         if(board[row][col] == 'Q'){
//             return false;
//         }
//         row--;
//         col--;
//     }
    
//     col = dupCol;
//     row = dupRow;
//     while (col>=0)
//     {
//         if(board[row][col] == 'Q'){
//             return false;
//         }
//         col--;
//     }
    
//     row = dupRow;
//     col = dupCol;
//     while (row<n && col >= 0)
//     {
//         if(board[row][col] == 'Q'){
//             return false;
//         }
//         row++;
//         col--;
//     }
//     return true;
// }

// void solve(int col, vector<string> &board, vector<vector<string>> &res, int n){
//     if(col == n){
//         res.push_back(board);
//         return;
//     }
//     for (int row = 0; row < n; row++)
//     {
//         if(isSafe1(row,col, board, n)){
//             board[row][col] = 'Q';
//             solve(col + 1, board, res, n);
//             board[row][col] = '.';
//         }
//     }
// }

// vector<vector<string>> solveNQueens(int n)
// {
//     vector<vector<string>> res;
//     vector<string> board(n);
//     string s(n, '.');
//     for(int i = 0; i < n; i++){
//         board[i] = s;
//     }
//     solve(0, board, res, n);
//     return res;
// }



// Optimised code

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if(leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n - 1 + col - row] = 0;
        }
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, res, leftRow, upperDiagonal, lowerDiagonal, n);
    return res;
}


int main(){
    int n;
    cin >> n;
    vector<vector<string>> res = solveNQueens(n);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}