#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<int> dp(8, 1 << 30);
    for(int i = 0; i < n; i++)
    {
        string s; int x;
        cin >> x >> s;
        int mask = 0;
        for(char c: s) mask |= 1 << (c - 'A');
        dp[mask] = min(dp[mask], x);
    }
    int ans = min({dp[7], dp[1] + dp[2] + dp[4], dp[1] + dp[6], dp[2] + dp[5]});
    ans = min({ans, dp[3] + dp[5], dp[3] + dp[6], dp[5] + dp[6], dp[3] + dp[4]});
    if(ans == (1 << 30))    ans = -1;
    cout << ans;
}