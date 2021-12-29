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
        int c[n + n + 1], d[n + n + 1];
        for(int i = 0; i < n; i++) {
            int x;  cin >> x; c[x] = i;
        }
        for(int i = 0; i < n; i++) {
            int x;  cin >> x; d[x] = i;
        }
        int suff[n];
        suff[n - 1] = d[n + n];
        for(int i = n - 2; i >= 0; i--)
            suff[i] = min(d[2 * (i + 1)], suff[i + 1]);
        int ans = 1e9;
        for(int i = 1, j = 0; i < n + n; i += 2)
            ans = min(ans, c[i] + suff[j++]);
        cout << ans << '\n';
    }
}