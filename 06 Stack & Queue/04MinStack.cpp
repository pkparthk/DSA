#include<bits/stdc++.h>
using namespace std;

// class MinStack {
//     stack<pair<int, int>> st;
// public:
//     void push(int x){
//         int min;
//         if(st.empty()){
//             min = x;
//         }
//         else
//         {
//             min = std :: min(st.top().second, x);
//         }
//         st.push({x, min});
//     }
//     void pop(){
//         st.pop();        
//     }
//     int top(){
//         return st.top().second;
//     }
// };

class MinStack
{
        stack<long> st; // Correct declaration of the stack
        long mini;

public:
    MinStack()
    {
        mini = LONG_MAX; // Initialize mini to a large value
    }

    void push(int value)
    {
        if (st.empty())
        {
            mini = value;
            st.push(value);
        }
        else
        {
            if (value < mini)
            {
                st.push(2 * (long)value - mini);
                mini = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        long t = st.top();
        st.pop();
        if (t < mini)
        {
            mini = 2 * mini - t;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1; // Could throw an exception instead
        }
        long t = st.top();
        return (t < mini) ? mini : t; // Return the correct top value
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{
    MinStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(5);
    cout << st.top() << endl; // Should print 5
    st.pop();
    cout << st.top() << endl;    // Should print 30
    cout << st.getMin() << endl; // Should print 10
    return 0;
}