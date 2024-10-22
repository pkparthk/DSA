#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

string PostfixToPrefix(string s){    
    stack<string> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (isOperand(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            st.push(s[i] + operand2 + operand1);            
        }
    }
    return st.top();
}

int main()
{
    string exp = "ABC/-AK/L-*";
    cout << "Postfix expression: " << exp << endl;
    cout << "Prefix expression: " << PostfixToPrefix(exp) << endl;
    return 0;
}