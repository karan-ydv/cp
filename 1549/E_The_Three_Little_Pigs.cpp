#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 3e6 + 69;
int fact[N], invf[N], dp[N];

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
int ncr(int n, int r)
{
    assert(r >= 0);
    if(r > n)  return 0;
    return fact[n] * invf[r] % mod * invf[n - r] % mod;
}
void fun(int n)
{
    dp[n] = 1;
    dp[n - 1] = n;
    for(int i = n - 2; i >= 1; i--)
        dp[i] = (ncr(n + 3, i + 3) + 3 * (mod - dp[i + 1]) + 3 * (mod - dp[i + 2]) ) % mod;
}
void compute(int n)
{
    n = 3 * n + 3;
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    invf[n] = modexp(fact[n], mod - 2);
    for(int i = n; i >= 1; i--)
        invf[i - 1] = invf[i] * i % mod;
    fun(n - 3);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;   cin >> n >> q;
    compute(n);
    while(q--)
    {
        int x;  cin >> x;
        cout << dp[x] << '\n';
    }
}