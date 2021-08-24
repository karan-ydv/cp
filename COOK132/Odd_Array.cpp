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
        int a[3] = {1, 2, 1};
        if(n <= 3) {
            for(int i = 0; i < n; i++)
                cout << a[i] << " \n"[i == n - 1];
            continue;
        }
        int ans[n], mx = 3 + (n  - 4) / 4;
        for(int i = 0; i < n; )
        {
            int j = 0;
            for(; j < mx and i < n; i++)
                ans[i] = ++j;
            for(; --j > 1 and i < n; i++)
                ans[i] = j;
        }
        for(int x: ans)
            cout << x << ' ';
        cout << '\n';
    }
}