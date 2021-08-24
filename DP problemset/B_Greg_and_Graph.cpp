#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 505;
int dp[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dp[i][j];
    int v[n];
    for (int &x : v)
        cin >> x;
    vector<int> ans;
    ans.reserve(n);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int &x = dp[v[i]][v[j]];
            int &y = dp[v[j]][v[i]];
            for (int k = i + 1; k < n; k++)
            {
                x = min(x, dp[v[i]][v[k]] + dp[v[k]][v[j]]);
                y = min(y, dp[v[j]][v[k]] + dp[v[k]][v[i]]);
            }
        }
        ans.emplace_back(0);
        for (int j = i; j < n; j++)
            for (int k = i; k < n; k++)
            {
                dp[v[j]][v[k]] = min(dp[v[j]][v[k]], dp[v[j]][v[i]] + dp[v[i]][v[k]]);
                ans.back() += dp[v[j]][v[k]];
            }
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans)
        cout << x << ' ';
}