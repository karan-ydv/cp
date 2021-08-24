#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n){
    int p = 1;
    while(n)
    {
        if(n & 1)	p = p * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return p;
}
int modinv;

int nc4(int n)
{
    if(n < 4)   return 0;
    int ret = 1;
    for(int i = n; i > n - 4; i--)
        (ret *= i) %= mod;
    (ret *= modinv) %= mod;
    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    modinv = modexp(24, mod - 2);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int ans = 2 * nc4(n) % mod * modexp(2, n - 4) % mod;
        cout << ans << '\n';
    }
}