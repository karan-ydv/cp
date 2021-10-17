#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 1e6 + 69;
int fact[N], invf[N];

int modexp(int a, int n)
{
    int p = 1;
    while(n)
    {
        if(n & 1)	p = p * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return p;
}
void compute(int n)
{
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    invf[n] = modexp(fact[n], mod - 2);
    for(int i = n; i >= 1; i--)
        invf[i - 1] = invf[i] * i % mod;
}
int ncr(int n, int r)
{
    assert(r >= 0);
    if(r > n)  return 0ll;
    return fact[n] * invf[r] % mod * invf[n - r] % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c, k;
    cin >> n >> c >> k;
}