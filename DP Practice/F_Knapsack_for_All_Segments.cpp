#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 998244353;
const int N = 3e3+5;
int a[N], dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;   cin >> n >> s;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[0] += 1;
        if(s >= a[i])
        (ans += dp[s - a[i]] * (n - i + 1)) %= mod;
        for(int j = s; j >= a[i]; j--)
            (dp[j] += dp[j - a[i]]) %= mod;
    }
    
    cout << ans;
}