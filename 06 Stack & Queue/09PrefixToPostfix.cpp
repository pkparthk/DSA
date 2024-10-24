#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

string PrefixToPostfix(string s){
    stack<string> st;
    int n = s.size();
    for (int i = n-1; i >= 0; i--)
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
            st.push(operand1 + operand2 + s[i]);            
        }
    } 
    return st.top();
}

int main()
{
    string exp = "*-A/BC-/AKL";
    cout << "Prefix expression: " << exp << endl;
    cout << "Postfix expression: " << PrefixToPostfix(exp) << endl;
    return 0;
}