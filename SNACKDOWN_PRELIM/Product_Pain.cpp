#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        long long ans = 0;
        for(int i = 0; i + 2 < n; i++)
        {
            set<int> set;
            set.insert(a[i]);
            set.insert(a[i + 1]);
            for(int j = i + 2; j < n; j++) {
                set.insert(a[j]);
                int mx = *set.rbegin();
                int mn = *set.begin();
                int mid = (mx + mn) / 2;
                auto itr = set.lower_bound(mid);
                int md = *itr;
                long long v = (long long)(mx - md) * (md - mn);
                md = *--itr;
                v = max(v, (long long)(mx - md) * (md - mn));
                ans += v;
            }
        }
        cout << ans << '\n';
    }
}