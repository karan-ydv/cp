#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 69;
int dp[N][N], p[N];
char prev[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[1] = 1;
    for(int i = 2; i < N; i++)
        p[i] = p[i - 1] * 10;

    string s; int n;
    cin >> n >> s;

    reverse(s.begin(), s.end());
    s = "!" + s;
    for(int i = 1; i <= n; i++)
        dp[i][0] = dp[0][i] = dp[i - 1][0] + p[i] * (s[i] - '0');
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        int x = s[i + j] - '0';
        dp[i][j] = max(dp[i - 1][j] + p[i] * x, dp[i][j - 1] + p[j] * x);
    }
    string ans;
    for(int i = n, j = n; i | j; )
    {
        int x = s[i + j] - '0';
        if(i != 0 and dp[i][j] == dp[i - 1][j] + p[i] * x)
            ans += 'H', --i;
        else
            ans += 'M', --j;
    }
    cout << ans;
}