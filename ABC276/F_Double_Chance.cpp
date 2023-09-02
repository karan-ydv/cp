#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5 + 69;
const int mod = 998244353;

int fastexp(int a, int n)
{
    int p = 1;
    for(; n; n >>= 1, (a *= a) %= mod)
        if(n & 1)	(p *= a) %= mod;
    return p;
}

struct Segtree
{
    int n; vector<int> t, c;
    Segtree(int n) : n(n)
    {
        t.resize(n << 1);
        c.resize(n << 1);
    }
    int range_sum(int l, int r, bool count = false) {  // sum on interval [l, r)
        int res = 0;
        vector<int> &v = count ? c : t;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) (res += v[l++]) %= mod;
            if(r & 1) (res += v[--r]) %= mod;
        }
        return res;
    }
    void modify(int p) {  // set value at position p
        for(t[p + n] += p, c[p += n]++; p > 1; p >>= 1)
            t[p >> 1] = (t[p] + t[p^1]) % mod,
            c[p >> 1] = (c[p] + c[p^1]) % mod;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    Segtree st(N);

    for(int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] + a[i];
        (ans[i] += 2 * st.range_sum(1, a[i] + 1, true) * a[i] % mod) %= mod;
        (ans[i] += 2 * st.range_sum(a[i] + 1, N) % mod) %= mod;
        st.modify(a[i]);
    }

    for(int k = 1; k <= n; k++) {
        int _1_k = fastexp(k, mod - 2);
        (ans[k] *= _1_k) %= mod;
        (ans[k] *= _1_k) %= mod;
        cout << ans[k] << "\n";
    }
}
