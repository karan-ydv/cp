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
        int n;	cin >> n; int a[n];
        for(int &x: a)    cin >> x;
        
        int p = 0, ans = 0;
        for(int i = 1; i < n - 1; i++)
            if(a[i] < a[p])
                ans += (i - p + 1) * a[p] - a[i],
                p = i;
        
        ans += (n - p) * a[p] - a[n - 1];
        cout << max(ans, int(0)) << '\n';
    }
}