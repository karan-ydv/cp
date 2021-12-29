#include <bits/stdc++.h>
using namespace std;

struct item {
    int x, y, z;
    item() : x(0), y(0), z(0) {}
};

inline item op(const item &a, const item &b) {
    item res{};
    int p = min(a.y, b.z);
    res.x = a.x + b.x + 2 * p;
    res.y = a.y + b.y - p;
    res.z = a.z + b.z - p;
    return res;
}

struct Segtree {
    int n;
    vector<item> t;
    Segtree() {
        string s;   cin >> s;
        n = (int) s.length();
        t.resize(n << 1);
        for(int i = 0; i < n; i++)
            (s[i] == '(' ? t[n + i].y : t[n + i].z)++;
        for(int i = n - 1; i > 0; i--)
            t[i] = op(t[i << 1], t[i << 1|1]);
    }
    item range_op(int l, int r) {  // op on interval [l, r)
        item resl{}, resr{};    // neutral value
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) resl = op(resl, t[l++]);
            if(r & 1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Segtree st{};
    int q;  cin >> q;
    while(q--)
    {
        int l, r;   cin >> l >> r;
        cout << st.range_op(--l, r).x << '\n';
    }
}