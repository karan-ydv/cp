#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int c[n + 1], m[n + 1], pref[n + 2] = {}, suff[n + 2] = {};
        for(int i = 1; i <= n; i++) cin >> c[i];
        for(int i = 1; i <= n; i++) cin >> m[i];
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
            pref[i] = min(c[i], m[i] + pref[i - 1]), ans = max(ans, pref[i]);
        for(int i = n; i >= 1; i--)
            suff[i] = min(c[i], m[i] + suff[i + 1]), ans = max(ans, suff[i]);
            
        for(int i = 1; i <= n; i++)
            ans = max(ans, min(c[i], pref[i - 1] + m[i] + suff[i + 1]));

        cout << ans << '\n';
    }
}