#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n) {
    int p = 1;
    for(; n; (a *= a) %= mod, n >>= 1)
        if(n & 1)	(p *= a) %= mod;
    return p;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        int x = modexp(2, n - 1);
        if(n & 1)
        {
            (x += 1) %= mod;
            cout << modexp(x, k) << '\n';
        }
        else
        {
            (x += mod - 1) %= mod;
            // cerr << x << '\n';
            int ans = 0, p = 1;
            for(int i = 1; i <= k; i++, (p *= x) %= mod)
            {
                ans += p * modexp(2, n * (k - i)) % mod;
                ans %= mod;
            }
            (ans += p) %= mod;
            cout << ans << '\n';
        }
    }
}