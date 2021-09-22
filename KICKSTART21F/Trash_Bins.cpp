#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int n;  string s;   cin >> n >> s;
        s = "!" + s + "!";
        int pref[n + 2] = {};
        pref[0] = -1e9;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '1')   pref[i] = i;
            else            pref[i] = pref[i - 1];
        }
        int suff[n + 2] = {};
        suff[n + 1] = 1e9;
        for(int i = n; i >= 1; i--) {
            if(s[i] == '1')   suff[i] = i;
            else            suff[i] = suff[i + 1];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += min(i - pref[i], suff[i] - i);
        }
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}