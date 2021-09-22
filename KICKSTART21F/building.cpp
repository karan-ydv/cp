#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    int dp[n] = {};
    int ans = 0;
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] >= a[i + 1])
            dp[i] = dp[i + 1] + 1;
        else
            dp[i] = 0;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}