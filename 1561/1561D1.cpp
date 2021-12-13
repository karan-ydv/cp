#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5+5;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, mod;  cin >> n >> mod;
    int sum = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int c = 1; c * c <= i; c++) {
            if(c != i / c)  (dp[i] += dp[i / c]) %= mod;
            (dp[i] += dp[c] * (i/c - i/(c + 1))) %= mod;
        }
        (dp[i] += sum) %= mod;
        (sum += dp[i]) %= mod;
    }
    cout << dp[n];
}