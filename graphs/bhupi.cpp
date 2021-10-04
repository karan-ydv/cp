#include <bits/stdc++.h>
using namespace std;

vector<int> findSubset(vector<int> &temp, int &last, int k)
{
    vector<int> ans;
    for (int i = last; i >= 0; i--)
    {
        int cnt = 0;
        for (auto it : temp)
        {
            int bit = it & (1 << i);
            if (bit > 0)
                cnt++;
        }
        if (cnt >= k)
        {
            for (auto it : temp)
            {
                int bit = it & (1 << i);
                if (bit > 0)
                    ans.push_back(it);
            }
            last = i - 1;
            return ans;
        }
    }
    return ans;
}

int findMaxiumAnd(int a[], int n, int k)
{
    int last = 31;
    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
        temp2.push_back(a[i]);
        
    while ((int)temp2.size() >= k)
    {
        temp1 = temp2;
        temp2 = findSubset(temp2, last, k);
    }

    int ans = temp1[0];
    for (int i = 0; i < k; i++)
        ans = ans & temp1[i];

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    int a[n + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    while (m--)
    {
        int k, y, x;
        cin >> k >> y >> x;
        int w = n - k + 1;
        int b[w];
        for (int i = 0; i + k <= n; i++)
            b[i] = (a[i + k] - a[i]) | x;
        cout << findMaxiumAnd(b, w, y) << ' ';
    }
}