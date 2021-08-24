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
        int n, q;   cin >> n >> q;
        int a[n + 2];
        a[0] = a[n + 1] = 1e15;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        map<int, int> mp;
        for(int i = 0; i <= n; i++) {
            mp[abs(a[i] - a[i + 1])]++;
        }
        auto fun = [&](int x) {
            mp[x]--;
            if(mp[x] == 0)
                mp.erase(x);
        };
        while(q--)
        {
            int k, p;   cin >> k >> p;
            fun(abs(a[k] - a[k + 1]));
            fun(abs(a[k] - a[k - 1]));
            a[k] = p;
            mp[abs(a[k] - a[k + 1])]++;
            mp[abs(a[k] - a[k - 1])]++;
            cout << mp.begin()->first << '\n';
        }
    }
}