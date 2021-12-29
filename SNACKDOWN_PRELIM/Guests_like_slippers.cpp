#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 998244353;
const int N = 2e5+69;
int a[N], p[N];

struct Segtree {
    typedef int item;
    int n;
    vector<item> t;
    inline item op(item a, item b) { return (a + b) % mod; }
    Segtree(int n) : n(n) {
        t.resize(n << 1);
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
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], p[i] = i;

    sort(p, p + n + 1, [&](int x, int y){
        return a[x] < a[y] or (a[x] == a[y] and x > y);
    });

    Segtree st(n + 1);
    st.modify(0, 1);

    int ans = 1, idx = 0;
    for(int i = 1; i <= n; i++) {
        int sum = st.range_op(0, p[i]);
        (ans += sum) %= mod;
        st.modify(p[i], sum);
    }
    
    cout << ans;
}