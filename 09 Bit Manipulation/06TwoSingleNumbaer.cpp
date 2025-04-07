#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N)
{
    long long int XORR = 0;
    for (long long int i = 0; i < N; i++)
    {
        XORR ^= Arr[i];
    }
    long long int rightMostSetBit = (XORR & (XORR - 1)) ^ XORR;
    long long int b1 = 0, b2 = 0;
    for (long long int i = 0; i < N; i++)
    {
        if (Arr[i] & rightMostSetBit)
        {
            b1 ^= Arr[i];
        }
        else
        {
            b2 ^= Arr[i];
        }
    }
    return {b1, b2};
}

int main()
{
    long long int N;
    cin >> N;
    long long int Arr[N];
    for (long long int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    vector<long long int> ans = twoOddNum(Arr, N);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}