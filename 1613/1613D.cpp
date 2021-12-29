#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int M = 998244353;
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

const int N = 5e5+69;
int a[N], f[N], g[N];
Z dp[N], p[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    p[0] = 1;
    for(int i = 1; i < N; i++)
        p[i] = 2 * p[i - 1];
    
    dp[0] = 1;
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        fill_n(f, n + 5, 0);
        
        for(int i = 1; i <= n; i++) cin >> a[i], dp[i] = 0;
        for(int i = n; i >= 1; i--)
            g[i] = f[a[i]]++ + (a[i] > 1 ? f[a[i] - 2] : 0);
        
        Z ans = dp[n + 1] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i])
                ans += dp[a[i] - 1] * p[g[i]];
            Z x = dp[a[i] + 1] + dp[a[i]];
            dp[a[i] + 1] += x;
            ans += x;
        }
        cout << ans.x << '\n';
    }
}