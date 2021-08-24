#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 5e3+5;
int dp[N][N];
int A[N], pref[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++)  cin >> A[i];
    partial_sum(A, A + n, pref + 1);
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if(j >= m)
            dp[i][j] = max(dp[i - 1][j - m] + pref[j] - pref[j - m], dp[i][j]);
        }
    }
    cout << dp[k][n];
}