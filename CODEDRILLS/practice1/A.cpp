#include <bits/stdc++.h>
#define int int64_t
using namespace std;


template<class T>
T power(T a, int n)
{
    T res = 1;
    for (; n; n >>= 1, a *= a)
        if (n & 1)  res *= a;
    return res;
}
struct Mint
{
    int x;
    Mint(int x = 0) : x(x)
    {
        if(x < 0)   
    }
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};







const int mod = 1e9+7;
const int N = 1e6 + 69;
int fact[N], invf[N];

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
    int t;	cin >> t;
    while(t--)
    {
        int n, k, g;    cin >> n >> k >> g;
        g = n / g;
        int p = ncr(n - k - 1, g - 1);
        int q = ncr(n - 1, g - 1);
        int ans = p * modexp(q, mod - 2);
    }
}