#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n) {
    int p = 1;
    for(; n; (a *= a) %= mod, n >>= 1)
        if(n & 1)   (p *= a) %= mod;
    return p;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("even.in", "r", stdin);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int b = __builtin_popcountll(n - 1);
        int e = modexp(2, b);
        int o = (n - e + mod) % mod;
        int ans = (e * (e - 1) + o * (o - 1)) % mod;
        (ans *= modexp(2, mod - 2)) %= mod;
        cout << ans << '\n';
    }
}