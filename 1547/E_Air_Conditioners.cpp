#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;	cin >> q;
    while(q--)
    {
        int n, k;	cin >> k >> n;
        
        pair<int, int> a[n];
        for(auto &[x, y]: a)   cin >> x;
        for(auto &[x, y]: a)   cin >> y;
        sort(a, a + n);

        int pref[n], suff[n];
        for(int i = 0; i < n; i++)
            pref[i] = a[i].second - a[i].first,
            suff[i] = a[i].second + a[i].first;

        for(int i = 1; i < n; i++)
            pref[i] = min(pref[i], pref[i - 1]);
        for(int i = n - 2; i >= 0; i--)
            suff[i] = min(suff[i], suff[i + 1]);

        for(int i = 1; i <= k; i++)
        {
            pair<int, int> p = {i, -2e9};
            int j = lower_bound(a, a + n, p) - a;
            int x = 2e9;
            if(j < n) x = min(x, suff[j] - i);
            if(j > 0) x = min(x, pref[j - 1] + i);
            cout << x << ' ';
        }
        cout << '\n';
    }
}