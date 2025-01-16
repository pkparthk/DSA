#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    int ans = start ^ goal;
    int count = 0;
    for (int i = 0; i < 31; i++)
    {
        if (ans & (1 << i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int start, goal;
    cin >> start >> goal;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}