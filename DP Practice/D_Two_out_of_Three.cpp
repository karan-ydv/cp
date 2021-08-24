#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int dp[N][N], A[N];
pair<int, int> par[N][N];
pair<int, int> str[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;  cin >> m;
    n = m;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    if(n & 1)   n += 1;

    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
        dp[i][j] = 2e9;

    dp[1][2] = 0;
    int ans = 2e9;
    for(int i = 1; i < n; i++)
    {
        int x;
        for(int j = i + 1; j < n - 1; j++)
        {
            x = dp[i][j] + max(A[j], A[j + 1]);
            if(dp[i][j + 2] > x)
            {
                dp[i][j + 2] = x;
                par[i][j + 2] = {i, j};
                str[i][j + 2] = {j, j + 1};
            }
            x = dp[i][j] + max(A[i], A[j + 1]);
            if(dp[j][j + 2] > x)
            {
                dp[j][j + 2] = x;
                par[j][j + 2] = {i, j};
                str[j][j + 2] = {i, j + 1};
            }
            x = dp[i][j] + max(A[i], A[j]);
            if(dp[j + 1][j + 2] > x)
            {
                dp[j + 1][j + 2] = x;
                par[j + 1][j + 2] = {i, j};
                str[j + 1][j + 2] = {i, j};
            }
        }
        x = dp[i][n] + max(A[i], A[n]);
        if(ans > x)
        {
            par[n][n] = {i, n};
            ans = x;
        }
    }
    auto [x, y] = par[n][n];
    stack<string> stk;
    while(!(x == 1 and y == 2))
    {
        auto [a, b] = str[x][y];
        stk.push(to_string(a) + " " + to_string(b));
        tie(x, y) = par[x][y];
    }

    cout << ans << '\n';
    while(!stk.empty())
    {
        cout << stk.top() << '\n';
        stk.pop();
    }
    tie(x, y) = par[n][n];
    cout << x << " ";
    if(n == m) cout << m;
}