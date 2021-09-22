#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e6+69;
long double dp[N + 1];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);

    for(int i = 1; i <= N; i++)
        dp[i] = dp[i - 1] + (long double) 1 / i;
    
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int n;  cin >> n;
        double ans = dp[min(n, N)];
        if(n > N)
            ans += logl(n) - logl(N);
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}