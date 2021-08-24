#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int ans = 0;
        int g[3][3] = {};
        for(int i : {0, 1, 2})
            cin >> g[0][i];
        for(int i : {0, 2})
            cin >> g[1][i];
        for(int i : {0, 1, 2})
            cin >> g[2][i];
        // for(int i = 0; i < 3; i++)  
        //     for(int j = 0; j < 3; j++)
        //         cerr << g[i][j] << " \n"[j == 2];
        ans += (g[0][0] + g[0][2]) == 2 * g[0][1];
        ans += (g[2][0] + g[2][2]) == 2 * g[2][1];
        ans += (g[0][0] + g[2][0]) == 2 * g[1][0];
        ans += (g[0][2] + g[2][2]) == 2 * g[1][2];
        map<int, int> mp;
        mp[g[0][0] + g[2][2]]++;
        mp[g[0][2] + g[2][0]]++;
        mp[g[0][1] + g[2][1]]++;
        mp[g[1][0] + g[1][2]]++;
        
        int cnt = 0;
        for(auto [x, f]: mp) if(x % 2 == 0)
            cnt = max(cnt, f);
        // cerr << cnt << '\n';
        ans += cnt;
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}