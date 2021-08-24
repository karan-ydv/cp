#include <bits/stdc++.h>
#define int int64_t
using namespace std;
     
struct Segtree {
    typedef int item;
    int n;
    vector<item> t;
    inline item op(item a, item b) { return __gcd(a, b); }
    Segtree(vector<item>& v) : n(v.size()) {
        t.resize(n << 1);
        copy(v.begin(), v.end(), t.begin() + n);
        build();
    }
    void build() {
        for(int i = n - 1; i > 0; i--)
            t[i] = op(t[i << 1], t[i << 1|1]);
    }
    item range_op(int l, int r) {  // op on interval [l, r)
        item res = 0;    // neutral value
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p, item value) {  // set value at position p
        for(t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        vector<int> d(n - 1);
        for(int i = 0; i + 1 < n; i++)
            d[i] = abs(a[i + 1] - a[i]);
        Segtree st(d);
        int ans = 0, L = 0;
        for(int R = 1; R < n; R++) {
            while(L < R and st.range_op(L, R) < 2)
                L++;
            ans = max(ans, R - L);
        }
        cout << ans + 1 << '\n';
    }
}