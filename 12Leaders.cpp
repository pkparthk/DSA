// LEADERS = It is that in a Array any element has right side does not have any bigger value than this.
// Ex {10, 22 , 12, 3, 0, 6}
// 22, 12, 6 are the leaders.

#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int maxi INT_MIN;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }

        // Keep track of right Maximum
        maxi = max(maxi, a[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> a;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> ans = superiorElements(a);
    cout << "The superior elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}