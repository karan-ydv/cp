#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int dp[N], a[N], pre[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int idx = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[mp[a[i] - 1]] + 1;
        pre[i] = mp[a[i] - 1];
        if (dp[i] > dp[idx])
            idx = i;
        if (dp[mp[a[i]]] < dp[i])
            mp[a[i]] = i;
    }
    cout << dp[idx] << '\n';
    stack<int> stack;
    while (idx != 0)
    {
        stack.push(idx);
        idx = pre[idx];
    }
    while (!stack.empty())
    {
        cout << stack.top() << ' ';
        stack.pop();
    }
}