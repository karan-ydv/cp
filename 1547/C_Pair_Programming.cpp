#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve()
{
    int k, n, m;    cin >> k >> n >> m;
    int a[n];   for(int &x: a)  cin >> x;
    int b[m];   for(int &x: b)  cin >> x;
    int ans[n + m];
    int p1 = 0, p2 = 0;
    int z = k;
    for(int i = 0; i < n + m; i++) {
        if(p1 < n and a[p1] <= z)
        {
            if(a[p1] == 0) z++;
            ans[i] = a[p1++];
        }
        else if(p2 < m)
        {
            if(b[p2] == 0) z++;
            ans[i] = b[p2++];
        }
        else return cout << "-1\n", void();
    }
    // for(int x: ans) cerr << x << ' '; cerr << '\n';
    for(int i = 0; i < n + m; i++) {
        if(ans[i] == 0) k++;
        else if(ans[i] > k)
            return cout << "-1\n", void();
    }
    for(int x: ans) cout << x << ' '; cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve();
    }
}