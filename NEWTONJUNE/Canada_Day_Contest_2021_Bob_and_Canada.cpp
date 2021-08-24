#include <bits/stdc++.h>
using namespace std;

const int N = 7.5e5 + 69;
int pref[N][2];
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s;
        int n;	cin >> n >> s;
        s = "!" + s;
        for(int i = 1; i <= n; i++) {
            for(int j: {0, 1})
                pref[i][j] = pref[i - 1][j];
            pref[i][s[i] == 'W'] += 1;
        }
        int ans = dp[1] = 1e9;
        for(int i = 2; i < n; i++)
        {
            dp[i] = (s[i] == 'R') + min(pref[i - 1][1], dp[i - 1]);
            ans = min(ans, dp[i] + (pref[n][1] - pref[i][1]));
        }
        cout << ans << '\n';
    }
}