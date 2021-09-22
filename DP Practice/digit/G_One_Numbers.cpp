#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int fun(string s)
{
    int n = s.length();
    int dp[n + 1][100][2] = {};
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 90; j++)
    {
        for(int d = 0; d < 10; d++)
            dp[i + 1][j + d][1] += dp[i][j][1];
        for(int d = 0; d <= s[i] - '0'; d++)
            dp[i + 1][j + d][d < s[i] - '0'] += dp[i][j][0];
    }
    int ans = 0;
    for(int p: primes)
        ans += dp[n][p][0] + dp[n][p][1];
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    while(n--)
    {
        int a, b;   cin >> a >> b;
        int ans = fun(to_string(b));
        if(a > 1)
            ans -= fun(to_string(a - 1));
        cout << ans << '\n';
    }
}