/* compile with 
g++ A2_Consistency_Chapter_2.cpp -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf = 1e16;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int dp[26][26];
        fill_n(dp[0], 26 * 26, inf);

        string s; int K; cin >> s >> K;
        for(int i = 0; i < K; i++) {
            char a, b;  cin >> a >> b;
            dp[a - 'A'][b - 'A'] = 1;
        }

        for(int i = 0; i < 26; i++)
            dp[i][i] = 0;
        
        for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
        if(dp[i][j] > dp[i][k] + dp[k][j])
            dp[i][j] = dp[i][k] + dp[k][j];

        int ans = inf;
        for(int i = 0; i < 26; i++)
        {
            int cnt = 0;
            for(char x: s) cnt += dp[x - 'A'][i];
            ans = min(ans, cnt);
        }
        if(ans == inf)  ans = -1;
        cout << ans << '\n';
    }
}