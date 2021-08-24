#include <bits/stdc++.h>
using namespace std;

struct Segtree
{
    int n, h;
    vector<int> t, d;
    const int neutral_value = 1e9;
    inline int op(int a, int b) { return min(a, b); }
    Segtree(vector<int> &v) : n(v.size()), h(32 - __builtin_clz(n)) {
        t.resize(n << 1);
        d.resize(n);
        copy(v.begin(), v.end(), t.begin() + n);
        build();
    }
    Segtree(int n) : n(n), h(32 - __builtin_clz(n)) {
        t.resize(n << 1);
        d.resize(n);
        for(int i = 0; i < n; i++)
            cin >> t[n + i];
        build();
    }
    void build() {
        for(int i = n - 1; i > 0; i--)
            t[i] = op(t[i << 1], t[i << 1|1]);
    }
    void apply(int p, int value) {
        t[p] += value;
        if(p < n)	d[p] += value;
    }

    void build(int p) {		// modify value of parents of p
        while(p > 1) p >>= 1, t[p] = op(t[p << 1], t[p << 1 | 1]) + d[p];
    }

    void push(int p) {		// propagate from root to p
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (d[i] != 0) {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }

    void increment(int l, int r, int value) {	// add v to interval [l, r)
        l += n, r += n;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if(l & 1) apply(l++, value);
            if(r & 1) apply(--r, value);
        }
        build(l0); build(r0 - 1);
    }

    int range_op(int l, int r) { 	// op of interval [l, r)
        l += n, r += n;
        push(l); push(r - 1);
        int res = neutral_value;
        for (; l < r; l >>= 1, r >>= 1) {
            if(l & 1)	res = op(res, t[l++]);
            if(r & 1)	res = op(t[--r], res);
        }
        return res;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    array<int, 3> a[n];
    for(auto &[w, l, r]: a) {
        cin >> l >> r >> w;
        l = 2 * (l - 1);
        r = 2 * (r - 1) + 1;
    }
    sort(a, a + n);
    m = m * 2 - 1;
    Segtree st(m);
    int ans = 1e9;
    for(int l = 0, r = -1; l < n; l++)
    {
        while(r + 1 < n and st.range_op(0, m) == 0)
        {
            r++;
            st.increment(a[r][1], a[r][2], 1);
        }
        if(st.range_op(0, m) == 0)
            break;
        ans = min(ans, a[r][0] - a[l][0]);
        st.increment(a[l][1], a[l][2], -1);
    }
    cout << ans;
}