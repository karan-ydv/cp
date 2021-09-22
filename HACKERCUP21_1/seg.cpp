#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree
{
    int n, h;
    vector<int> d;
    vector<double> Cos, Sin;
    Segtree(int n) : n(n), h(32 - __builtin_clz(n)) {
        Sin.resize(n << 1);
        Cos.resize(n << 1);
        d.resize(n);
        for(int i = 0; i < n; i++) {
            Cos[n + i] = cos(i);
            Sin[n + i] = sin(i);
        }
        for(int i = n - 1; i > 0; i--) {
            Cos[i] = Cos[i << 1] + Cos[i << 1|1];
            Sin[i] = Sin[i << 1] + Sin[i << 1|1];
        }
    }
    void apply(int p, int value) {
        double x = cos(value) * Sin[p] + sin(value) * Cos[p];
        double y = cos(value) * Cos[p] - sin(value) * Sin[p];
        Sin[p] = x;
        Cos[p] = y;
        if(p < n)	d[p] += value;
    }

    void build(int p) {		// modify value of parents of p
        while(p > 1)
        {
            p >>= 1;
            Cos[p] = Cos[p << 1] + Cos[p << 1|1];
            Sin[p] = Sin[p << 1] + Sin[p << 1|1];
            if(d[p])
            {
                double x = cos(d[p]) * Sin[p] + sin(d[p]) * Cos[p];
                double y = cos(d[p]) * Cos[p] - sin(d[p]) * Sin[p];
                Sin[p] = x;
                Cos[p] = y;
            }
        }
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
        double res = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if(l & 1) { res += Cos[l] + Sin[l]; l++; }
            if(r & 1) { --r; res += Cos[r] + Sin[r]; }
        }
        return floor(res);
    }
};


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;   cin >> n >> q;
    Segtree st(n);
    while(q--)
    {
        int l, r, type;
        cin >> type >> l >> r;
        if(type) {
            int value;  cin >> value;
            st.increment(l, r + 1, value);
        }
        else {
            cout << st.range_op(l, r + 1) << '\n';
        }
    }
}