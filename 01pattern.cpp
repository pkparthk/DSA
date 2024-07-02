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

void pattern10(int n){
    for (int i = 0; i <= 2 * n - 1;i++){
        int stars = i;
        if(i > n){
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;   
    }
}
void pattern11(int n){
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i%2==0){
            start = 1;
        }
        else{
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }       
}

void pattern12(int n){
    for (int i = 0; i < n; i++)
    {
        // number
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        // space
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << "  ";
        }
        // number
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 - j << " ";
        }
        cout << endl;
    }
}

void pattern13(int n){
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num <<" ";
            num++;
        }
        cout << endl;
    }
}

void pattern14(int n){
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern15(int n){
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch < 'A'+n-i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern16(int n){
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j<=i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;        
    }
}

void pattern17(int n){
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n-i-1; j++)
        {
            cout << " ";
        }
        // Alphabet
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2*i+1; j++)
        {
            cout << ch;
            // if(j <= (2*i+1)/2){
            //     ch++;
            // }
            // else{
            //     ch--;
            // }
            if(j <= breakpoint){
                ch++;
            }
            else{
                ch--;
            }
        }        
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern18(int n){
    for (int i = 0; i < n; i++)
    {
        char ch = 'A'+n-1;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch--;
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
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern8(n);
    //     cout << endl;
    // }

    // Patern 9
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern7(n);
    //     pattern8(n);
    //     cout << endl;
    // }

    // Pattern 10
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern10(n);
    //     cout << endl;
    // }

    // Pattern 11
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern11(n);
    //     cout << endl;
    // }

    // Pattern 12
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern12(n);
    //     cout << endl;
    // }

    // Pattern 13
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern13(n);
    //     cout << endl;
    // }

    // Pattern 14
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern14(n);
    //     cout << endl;
    // }

    // Pattern 15
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern15(n);
    //     cout << endl;
    // }

    // Pattern 16
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern16(n);
    //     cout << endl;
    // }

    // Pattern 17
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     // cout << "Enter te value for pattern";
    //     cin >> n;
    //     pattern17(n);
    //     cout << endl;
    // }

    // Pattern 18
    for (int i = 0; i < t; i++)
    {
        int n;
        // cout << "Enter te value for pattern";
        cin >> n;
        pattern18(n);
        cout << endl;
    }
    return 0;
}
