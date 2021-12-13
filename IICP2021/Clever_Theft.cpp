#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        k++;
        int a[n];   for(int &x: a)  cin >> x;
        int dp[n];  dp[0] = a[0];
        for(int i = 1; i < k; i++)
            dp[i] = max(a[i], dp[i - 1]);
        for(int i = k; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - k] + a[i]);
        }
        // for(int x: dp)  clog << x << ' ';
        // clog << '\n';
        cout << dp[n - 1] << '\n';
    }
}