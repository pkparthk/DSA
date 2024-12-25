#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    int n = asteroids.size();
    for (int i = 0; i < n; i++)
    {
        if (asteroids[i] > 0)
        {
            st.push(asteroids[i]);
        }
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
            {
                st.pop();
            }
            if (!st.empty() && st.top() == abs(asteroids[i]))
            {
                // Destroy both asteroids if they are equal in size
                st.pop();
            }
            else if (st.empty() || st.top() < 0)
            {
                // Push left-moving asteroid if no collision or all right-moving are destroyed
                st.push(asteroids[i]);
            }
        }
    }
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        result[i] = st.top();
        st.pop();
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> result = asteroidCollision(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}