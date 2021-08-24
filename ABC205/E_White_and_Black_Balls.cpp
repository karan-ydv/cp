#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 2e6+69;
int fact[N], finv[N];

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

void cum(int n)
{
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    
    finv[n] = modexp(fact[n], mod - 2);
    for(int i = n; i >= 1; i--)
        finv[i - 1] = finv[i] * i % mod;
}

int C(int n, int r)
{
    assert(r >= 0 and r <= n);
    return fact[n] * finv[r] % mod * finv[n - r] % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    int n, m, k;    cin >> n >> m >> k;

    if(n - m > k)
        return cout << 0, 0;

    if(n == 0 or m == 0)
        return cout << 1, 0;
    
    cum(m + n);

    if(k == n)
        return cout << C(n + m, n), 0;


    int ans = C(m + n, n) - C(m + n, n - k - 1) + mod;
    cout << ans % mod;
}