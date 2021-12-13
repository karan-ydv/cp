#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n){
    int p = 1;
    for(; n; n >>= 1, (a *= a) %= mod)
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
        int n;	cin >> n;
        int ans = (n * (n + 1) / 2) % mod;
        (ans *= ans) %= mod;
        int x = n * (n + 1) % mod * (2 * n + 1) % mod;
        (x *= modexp(6, mod - 2)) %= mod;
        (ans += mod - x) %= mod;
        (ans *= modexp(n, mod - 2)) %= mod;
        cout << ans << '\n';
    }
}