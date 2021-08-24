#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    inline int op(int a, int b) { return a + b; }
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
        for(int i = 0; i < n; i++)
            cin >> t[n + i];
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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n; int a[n];
    for(int &x: a)  cin >> x, x--;
    Segtree st(n);
    int inv = 0;
    for(int i = 0; i < n; i++)
        inv + st.range_op(a[i], n), st.modify(a[i], 1);
    cout << inv;
}