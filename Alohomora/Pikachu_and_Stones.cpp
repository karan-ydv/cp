#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n + 1], b[n + 1], c[n + 1];
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        b[1] = a[1];
        c[n] = a[n];
        int pref[n + 2] ={}, suff[n + 2]={};
        for(int i = 2; i < n; i++) {
            b[i] = max(b[i - 1] + 1, a[i]);
            pref[i] = pref[i - 1] + max(0ll, b[i] - a[i]);
        }
        for(int i = n - 1; i > 1; i--) {
            c[i] = max(c[i + 1] + 1, a[i]);
            suff[i] = suff[i + 1] + max(0ll, c[i] - a[i]);
        }
        
        int ans = 1e18;
        for(int i = 2; i < n; i++) {
            ans = min(ans, pref[i - 1] + suff[i + 1] + max(0ll, max(b[i - 1], c[i + 1]) + 1 - a[i]));
        }
        cout << ans << '\n';
    }
}