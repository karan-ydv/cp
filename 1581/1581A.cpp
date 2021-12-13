#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+5;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = 1;
    for(int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] * i % mod;
    }

    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int ans = n * dp[2 * n - 1] % mod;
        cout << ans << '\n';  
    }
}