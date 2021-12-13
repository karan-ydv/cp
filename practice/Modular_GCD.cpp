#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t mod = 1e9+7;

int modexp(__int128_t a, int n, int m = mod){
    a %= m;
    __int128_t p = 1;
    while(n)
    {
        if(n & 1)	p = p * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return (int) p;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if(a > b)   swap(a, b);

        int ans, d = b - a;
        if(d == 0)
            ans = (modexp(a, n) + modexp(b, n)) % mod;
        else {
            ans = __gcd(modexp(a, n, d) + modexp(b, n, d), d) % mod;
        }
        cout << ans << '\n';
    }
}