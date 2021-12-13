#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+5;
const int K = 450;
int dp[N][K];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        int pref[n + 1]{};
        for(int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + a[i - 1];

        int k = (int) sqrt(2 * n);

        for(int i = 0; i <= n; i++)
        for(int j = 1; j <= k; j++)
            dp[i][j] = (int) -1e18;
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = (int) 1e18;

        for(int i = n - 1; i >= 0; i--)
        for(int j = 1; j <= k and i + j <= n; j++)
        {
            dp[i][j] = dp[i + 1][j];
            int sum = pref[i + j] - pref[i];
            if(dp[i + j][j - 1] > sum)
                dp[i][j] = max(dp[i][j], sum);
        }
        
        int ans = 1;
        for(int i = 1; i <= k; i++)
            if(dp[0][i] > 0) ans = i;
        cout << ans << '\n';
    }
}