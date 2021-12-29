#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int M = 1e9+7;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0)  x += M;
    if (x >= M) x -= M;
    return x;
}
 
template<class T>
T power(T a, int n) {
    T p = 1;
    for (; n; n >>= 1, a *= a)
        if (n & 1)  p *= a;
    return p;
}
 
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    Z operator-() const { return Z(norm(M - x)); }
    Z inv() const {
        assert(x != 0);
        return power(*this, M - 2);
    }
    Z &operator*=(const Z &rhs) {
        (x *= rhs.x) %= M;
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

const int N = 1e7+7;
Z f[N], dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    for(int i = 1; i < N; i++)
        f[i] = f[i - 1] * i;
    
    Z v = 1 / f[N - 1];
    for(int i = N - 1; i > 0; i--) {
        dp[i] = f[i - 1] * v;
        v *= i;
    }
    
    for(int i = 1; i < N; i++)
        dp[i] += dp[i - 1];

    int t;  cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        Z ans = dp[n - 1] - dp[k] - (dp[n] - dp[n - 1]) * (n - 1 - k);
        ans *= f[n];
        cout << ans.x << '\n';
    }
}