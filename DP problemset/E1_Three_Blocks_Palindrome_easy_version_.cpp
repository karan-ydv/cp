#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int alpha = 205;
int dp[N][alpha];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A[alpha];
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            A[x].emplace_back(i);
            for (int a = 1; a < alpha; a++)
                dp[i][a] = dp[i - 1][a];
            dp[i][x] += 1;
        }
        int ans = 1;
        for (int i = 1; i < alpha; i++)
        {
            int l = 0, r = A[i].size() - 1;
            while (l < r)
            {
                for (int j = 1; j < alpha; j++)
                    ans = max(ans, 2 * l + 2 + dp[A[i][r] - 1][j] - dp[A[i][l]][j]);
                l++, r--;
            }
        }
        cout << ans << '\n';
    }
}