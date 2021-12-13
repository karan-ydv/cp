#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int dp[101]{};
    dp[0] = 1;
    for(int i = 1; i <= 100; i++)
    for(int j = 1; j <= i; j++)
        dp[i] = max(dp[i - j] * j, dp[i]);
    for(int x: dp)  clog << x << '\n';
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        cout << dp[n] << '\n';
    }
}