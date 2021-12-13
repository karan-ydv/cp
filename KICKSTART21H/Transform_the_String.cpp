#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        string s, f;
        cin >> s >> f;
        int ans = 0;
        for(char c: s)
        {
            int mn = 1e9;
            for(char x: f)
            {
                int d = int(26 + x - c) % 26;
                mn = min({mn, d, 26 - d});
            }
            ans += mn;
        }
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}