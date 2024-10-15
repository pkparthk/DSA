#include<bits/stdc++.h>
using namespace std;

bool IsValid(string s){
    stack<char> st;    
    for(auto it: s){
        if (it=='(' || it=='{' || it=='[')
        {
            st.push(it);
        }
        else{
            if (st.size()==0)
            {
                return false;
            }
            char ch = st.top();
            st.pop();            
            if ((ch=='(' && it==')') || (ch=='['&& it==']') || (ch=='{' && it=='}'))
            {
                continue;
            }
            else
            {
                return false;
            }                        
        }                
    }
    return st.empty();
}


int main()
{
    string s = "{[()]}";
    if (IsValid(s))
    {
        cout << "Balanced Parantheses" << endl;
    }
    else
    {
        cout << "Not Balanced Parantheses" << endl;
    }
    return 0;
}