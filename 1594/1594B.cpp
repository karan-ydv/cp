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
        int n, k;   cin >> n >> k;
        int ans = 0, p = 1;
        while(k)
        {
            if(k & 1)
                (ans += p) %= mod;
            (p *= n) %= mod;
            k >>= 1;
        }
        cout << ans << '\n';
    }
}