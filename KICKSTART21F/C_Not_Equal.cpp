#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 998244353;
int dp[1001][1001];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    int sum = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= a[i]; j++) {
            dp[i][j] = (sum + mod - dp[i - 1][j]) % mod;
        }
        sum = 0;
        for(int j = 1; j <= a[i]; j++) {
            (sum += dp[i][j]) %= mod;
        }
    }
    cout << sum;
}