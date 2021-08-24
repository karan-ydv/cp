#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    Segtree(vector<int>& v) {
        n = v.size();
        t.resize(n << 1);
        copy(v.begin(), v.end(), t.begin() + n);
        build();
    }
    int f(int a, int b)
    {
        if(a == b)
        {
            if(a == 1 or a == 0)
                return a;
            return 3;
        }
        if(a == 0 and (b == 0 or b == 1 or b == 2))
            return 2;
        else if(a == 2 and b == 1)
            return 2;
        return 3;
    }
    int op(int a, int b)
    {
        cerr << a << ' ' << b << ' ' << f(a, b) << '\n';
        return f(a, b);
    }
    void build() {
        for(int i = n - 1; i > 0; i--)
            t[i] = op(t[n << 1], t[n << 1|1]);
    }
    bool range_query(int l, int r) {  // query on interval [l, r)
        int resl = 0, resr = 1;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) resl = op(resl, t[l++]);
            if(r & 1) resr = op(t[--r], resr);
        }
        // cerr << resl << ' ' << resr << ' ';
        // cerr << op(resl, resr) << '\n';
        return op(resl, resr) != 3;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    vector<int> a(n), b(n);
    for(int &x: a)  cin >> x;
    
    for(int i = 1; i < n; i++)
        b[i] = a[i] <= a[i - 1];

    // for(int x: b)   cerr << x << ' '; cerr << '\n';
    Segtree st(b);
    while(m--)
    {
        cerr << m << '\n';
        int l, r;   cin >> l >> r;
        if(st.range_query(--l, r))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}