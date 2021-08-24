#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
        for(int i = 0; i < n; i++)
        {
            int x;  cin >> x;
            t[n + i] = (__builtin_popcount(x) & 1);
        }
        build();
    }
    void build() {
        for(int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1|1];
    }
    int elements_with_odd_bits(int l, int r) {
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res += t[l++];
            if(r & 1) res += t[--r];
        }
        return res;
    }
    void modify(int p, int x) {  // set value at position p
        for(t[p += n] = (__builtin_popcount(x) & 1); p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p^1];
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    Segtree st(n);
    int q, r; cin >> q >> r;
    while(q--)
    {
        int t;  cin >> t;
        if(t == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int cnt = st.elements_with_odd_bits(l - 1, r);
            if(cnt >= k and (cnt - k) % 2 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            int l, x, y;
            cin >> l >> x >> y;
            st.modify(l - 1, x);
        }
    }
}