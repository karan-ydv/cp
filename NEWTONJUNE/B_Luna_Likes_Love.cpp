#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
    }
    inline int op(int a, int b) { return a + b; }
    int range_sum(int l, int r) {  // min on interval [l, r)
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p) {  // set value at position p
        for(t[p += n] ^= 1; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int last[n + 1] = {};
    Segtree st(n + n);
    long long ans = n;
    for(int i = 0; i < n + n; i++) {
        int x;  cin >> x;
        if(last[x]) {
            ans += st.range_sum(last[x], i);
            st.modify(last[x] - 1);
        }
        else {
            last[x] = i + 1;
            st.modify(i);
        }
    }
    cout << ans;
}