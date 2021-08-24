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
        int a[n + 1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<tuple<int, int, int>> q;
        for(int i = 1; i <= n; i += 2)
        {
            q.emplace_back(1, i, i + 1);
            q.emplace_back(2, i, i + 1);
            q.emplace_back(1, i, i + 1);
            q.emplace_back(2, i, i + 1);
            q.emplace_back(1, i, i + 1);
            q.emplace_back(2, i, i + 1);

            a[i] += a[i + 1];
            a[i + 1] -= a[i];
            a[i] += a[i + 1];
            a[i + 1] -= a[i];
            a[i] += a[i + 1];
            a[i + 1] -= a[i];
        }
        // for(int i = 1; i <= n; i++) cerr << a[i] << ' '; cerr << '\n';
        cout << q.size() << '\n';
        for(auto [a, b, c]: q)  cout << a << ' ' << b << ' ' << c << '\n';
    }
}