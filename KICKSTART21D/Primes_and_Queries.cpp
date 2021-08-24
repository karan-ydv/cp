#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    inline int op(int a, int b) { return a + b; }
    Segtree() {}
    Segtree(vector<int>& v) {
        n = v.size();
        t.resize(n << 1);
        copy(v.begin(), v.end(), t.begin() + n);
        build();
    }
    void build() {
        for(int i = n - 1; i > 0; i--)
            t[i] = op(t[i << 1], t[i << 1|1]);
    }
    int range_op(int l, int r) {  // op on interval [l, r)
        int res = 0;    // neutral value
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p, int value) {  // set value at position p
        for(t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

int degree(int a, int p, int s)
{
    if(a < p)   return 0;
    int b = a % p;
    int y = 1, z = 1;
    for(int i = 0; i < s; i++) {
        y *= a;
        z *= b;
    }
    y -= z;
    int cnt = 0;
    while(y % p == 0)
    {
        cnt++;
        y /= p;
    }
    return cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n, q, p;    cin >> n >> q >> p;
        vector<int> a(n), v(n);  for(int &x: a)  cin >> x;

        Segtree st[4];
        for(int j = 0; j < 4; j++)
        {
            for(int i = 0; i < n; i++)
                v[i] = degree(a[i], p, j + 1);
            st[j] = Segtree(v);
        }
        while(q--)
        {
            int a;  cin >> a;
            if(a == 1)
            {
                int idx, val; cin >> idx >> val;
                for(int i = 0; i < 4; i++) {
                    st[i].modify(idx - 1, degree(val, p, i + 1));
                }
            }
            else
            {
                int s, l, r;
                cin >> s >> l >> r;
                assert(s < 5);
                cout << st[s - 1].range_op(l - 1, r) << ' ';
            }
        }
        cout << '\n';
    }
}