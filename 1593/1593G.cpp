#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree {
    typedef int item;
    int n;
    vector<item> t;
    inline item op(item a, item b) { return a + b; }
    Segtree(string s) {
        n = s.size();
        t.resize(n << 1);
        for(int i = 0; i < n; i++)
            t[n + i] = s[i] - '1';
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
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s;   cin >> s;
        for(char &x: s)
            x = (x == '(' or x == ')') ? '0' : '1';
        int q;  cin >> q;
        while(q--)
        {
            int l, r;   cin >> l >> r;
            l--, r--;
            int ans = 0;
            while(l < r)
            {
                ans += (s[l] != s[r]);
                l++, r--;
            }
            cout << ans << '\n';
        }

    }
}