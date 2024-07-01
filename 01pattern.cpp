// #include<iostream>
#include <bits/stdc++.h>        //It is for all the libraries
using namespace std;

void pattern1(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
}

void pattern2(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern3(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void pattern4(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i+1 << " ";
        }
        cout << endl;
    }
}

void pattern5(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n-i+1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n-i+1; j++)
        {
            cout << j+1 << " ";
        }
        cout << endl;
    }
}

void pattern7(int n){
    for (int i = 0; i < n;i++){
        // Space
        for (int j = 0; j < n-i-1; j++)
        {
            cout << " ";
        }
        // Stars
        for (int j = 0; j < 2*i+1; j++)
        {
            cout << "*";
        }
        // Space
        for (int j = 0; j < n-i-1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(int n){
    for (int i = 0; i < n; i++)
    {
        // Space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // Stars
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }
        // Space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    // int n;
    // cin >> n;
    // print1(n);

    int t;
    // cout << "Enter The number of patterns to form";
    cin >> t;
    
    // Pattern 1
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern1(n);
    //     cout << endl;
    // }

    // Pattern 2
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern2(n);
    //     cout << endl;
    // }

    // Pattern 3
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern3(n);
    //     cout << endl;
    // }

    // Pattern 4
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern4(n);
    //     cout << endl;
    // }

    // Pattern 5
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern5(n);
    //     cout << endl;
    // }

    // Pattern 6
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern6(n);
    //     cout << endl;
    // }

    // Pattern 7
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern7(n);
    //     cout << endl;
    // }

    // Pattern 8
    for (int i = 0; i < t; i++)
    {
        int n;
        // cout << "Enter te value for pattern";
        cin >> n;
        pattern8(n);
        cout << endl;
    }

    return 0;
}
