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
        pair<int, int> a[n + 1];
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a + 1, a + 1 + n);
        for(auto [f, s]: a) cerr << f << ' '; cerr << '\n';
        for(auto [f, s]: a) cerr << s << ' '; cerr << '\n';
        cerr << '\n';
    }
}