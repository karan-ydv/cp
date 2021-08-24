#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 105;
int A[N], dp[N][N];
int pref[N];

// dp[i][j] = minimum smoke generated when
// solutions from [i, j] are mixed

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    while(cin >> n)
    {
        for(int i = 0; i < n; i++) cin >> A[i];
        partial_sum(A, A + n, pref + 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j + i <= n; j++)
            {
                dp[j][j + i] = 1e9;
                for(int k = j; k < j + i; k++)
                {
                    int x = dp[j][k] + dp[k + 1][j + i];
                    int y = (pref[k] - pref[j - 1]) % 100;
                    (y *= (pref[j + i] - pref[k]) % 100) % 100;
                    dp[j][j + i] = min(dp[j][j + i], x + y);
                }
                // cerr << j << ' ' << j + i << " : " << dp[j][j + i] << '\n';
            }
        }
        cout << dp[1][n] << '\n';
    }
}