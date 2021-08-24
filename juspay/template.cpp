#include <bits/stdc++.h>
#define int int64_t
using namespace std;

// const int mod = 1e9+7;
const int mod = 5;
const int N = 200;
int fact[N], finv[N], inv[N];

void cum()
{
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = inv[1] = 1;
    for(int i = 2; i < N; i++)
    {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        fact[i] = fact[i - 1] * i % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
        cout << i << ' ' << inv[i] << '\n';
    }
}

int ncr(int n, int r)
{
    if(r > n) return 0;
    return fact[n] * finv[r] % mod * finv[n - r] % mod;
}
int lucasNcR(int n, int r, int p)
{
    int ans = 1;
    while(r)
    {
        (ans *= ncr(n % p, r % p)) %= p;
        n /= p;
        r /= p;
    }
    return ans;
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cum();
    cout << lucasNcR(127, 15, 2);
}