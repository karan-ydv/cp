#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        if(n < 3)
        {
            cout << n << '\n';
            continue;
        }
        int b = 64 - __builtin_clzll(n);
        int ans = (1ll << b);
        if(n & (n - 1));
        else
            ans--;
        cout << ans % mod << '\n';
    }
    // for(int n = 1; n <= 100; n++) {
    //     int b = 64 - __builtin_clzll(n);
    //     int ans = (1ll << b);
    //     if(n & (n - 1));
    //     else
    //         ans--;
    //     set<int> set;
    //     for(int i = 1; i <= n; i++)
    //     for(int j = i + 1; j <= n; j++)
    //         set.insert(i ^ j);
    //     cout << n << " : " << set.size() + 1 << " - " << ans << '\n';
    // }
}