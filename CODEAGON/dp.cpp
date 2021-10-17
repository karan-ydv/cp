#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, y;   cin >> n >> y;
    int a[n], dp[n];
    for(int &x: a)  cin >> x;
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = a[0] + min(a[1], y) + a[2];
    for(int i = 3; i < n; i++) {
        dp[i] = a[i] + min({dp[i - 1], dp[i - 2] + min(a[i - 1], y),
                dp[i - 3] + min(a[i - 2], y) + min(a[i - 1], y)});
    }
    cout << dp[n - 1];
}