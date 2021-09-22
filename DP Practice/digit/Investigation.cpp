#include <bits/stdc++.h>
using namespace std;

const int K = 100;
int dp[2][K][K][2];

void zero(int c, int k) {
    for(int a = 0; a < k; a++)
    for(int b = 0; b < k; b++)
        dp[c][a][b][0] = dp[c][a][b][1] = 0;
}
int fun(string s, int k)
{
    int n = s.size();
    zero(0, k);
    zero(1, k);
    dp[0][0][0][0] = 1;
    for(int i = 0, c = 0; i < n; i++, c ^= 1)
    {
        zero(c ^ 1, k);
        for(int a = 0; a < k; a++)
        for(int b = 0; b < k; b++)
        {
            for(int d = 0; d < 10; d++)
                (dp[c ^ 1][(a + d) % k][(b * 10 + d) % k][1] += dp[c][a][b][1]);
            for(int d = 0; d <= s[i] - '0'; d++)
                (dp[c ^ 1][(a + d) % k][(b * 10 + d) % k][d < s[i] - '0'] += dp[c][a][b][0]);
        }
    }
    return dp[n & 1][0][0][0] + dp[n & 1][0][0][1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int _t;	cin >> _t;
    for(int __t = 1; __t <= _t; __t++)
    {
        cout << "Case " << __t << ": ";
        string b; int a, k;
        cin >> a >> b >> k;
        if(k > 83)
        {
            cout << "0\n";
            continue;
        }
        int ans = fun(b, k);
        if(a > 1)   ans -= fun(to_string(a - 1), k);
        else        ans --;
        cout << ans << '\n';
    }
}