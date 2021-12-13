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
        int a[n];   for(int &x: a)  cin >> x;
        vector<int> e, o;
        for(int i = 0; i < n; i++)
        if(i & 1)   o.emplace_back(a[i]);
        else        e.emplace_back(a[i]);
        sort(e.rbegin(), e.rend());
        sort(o.begin(), o.end());
        int ans = 0, i = 0, sum = 0;
        for(int x: e)   a[i] = x, i += 2;
        i = 1;
        for(int x: o)   a[i] = x, i += 2, sum += x;
        for(i = 0; i < n; i ++)
        {
            if(i & 1)
                sum -= a[i];
            else
                ans += a[i] * sum;
        }
        for(int x: a)   cout << x << ' ';
        cout << '\n' << ans << '\n';
    }
}