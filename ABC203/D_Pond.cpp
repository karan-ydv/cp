#include <bits/stdc++.h>
using namespace std;

const int N = 808;
int a[N][N], dp[N][N];

int n, k, m;
bool possible(int med)
{ // return true if median <= med is possible
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (a[i][j] <= med);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
            if (dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k] >= m)
                return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    m = (k * k + 1) / 2;
    int beg = 0, end = 1e9, ans;
    while (beg <= end)
    {
        int mid = beg + end >> 1;
        if (possible(mid))
            ans = mid, end = mid - 1;
        else
            beg = mid + 1;
    }
    cout << ans;
}