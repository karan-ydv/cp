#include <bits/stdc++.h>
#define int int64_t
using namespace std;

// const int N = 2e5+69;
const int N = 200;
const int mod = 998244353;
int fact[N], invf[N];
int A[N], P[N], dp[N][2];

int modexp(int a, int n)
{
    int p = 1;
    while(n)
    {
        if(n & 1)	p = p * a % mod;
        a = a * a % mod; n >>= 1;
    }
    return p;
}

void cum()
{
    fact[0] = invf[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        invf[i] = modexp(fact[i], mod - 2);
    }
}

int nCr(int n, int r)
{
    int ret = 1;
    r = min(r, n - r);
    for(int i = n; i > n - r; i--) (ret *= i) %= mod;
    return ret * invf[r] % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cum();
    
    int r;  cin >> r;
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++)
        cin >> P[i];
    
    dp[0][0] = (1 - P[0] + mod) % mod;
    dp[0][1] = P[0] * nCr(A[0], r) % mod;

    int temp = (dp[0][0] + dp[0][1]) % mod;

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = (1 - P[i] + mod) % mod * temp;
        dp[i][1] = P[i] * nCr(A[i], r) % mod * temp % mod;
        temp = (dp[i][0] + dp[i][1]) % mod;
    }

    cout << temp;
}