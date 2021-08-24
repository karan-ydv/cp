#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        int a[n], ans[n] = {};
        for(int &x: a)  cin >> x;
        for(int i = 1, x = 1e9; i < n; i++, x++)
        {
            if(a[i] == 1)   ans[i] = x = 0;
            else            ans[i] = x;
        }
        for(int i = n - 1, x = 1e9; i > 0; i--, x++)
        {
            if(a[i] == 2)   ans[i] = x = 0;
            else            ans[i] = min(ans[i], x);
            if(ans[i] > 1e6) ans[i] = -1;
        }
        while(m--)
        {
            int x;  cin >> x;
            cout << ans[--x] << ' ';
        }
        cout << '\n';
    }
}