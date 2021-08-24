#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int ans[N], dp[N];

void cum()
{
    fill_n(dp, N, 1);
    fill_n(ans, N, 1);
    for(int i = 1; i < N; i++)
        for(int j = i + i + 1; j < N; j += i)
                dp[j] = max(dp[j], dp[i] + 1);
    for(int i = 3; i < N; i++)
        for(int j = i; j < N; j += i)
                ans[j] = max(ans[j], dp[j / i]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cum();
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int n;  cin >> n;
        cout << "Case #" << _ << ": " << ans[n] << '\n';
    }
}