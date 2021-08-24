#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    inline int op(int a, int b) { return __gcd(a, b); }
    Segtree(vector<int>& v) {
        n = v.size();
        t.resize(n << 2);
        copy(v.begin(), v.end(), t.begin() + n + n);
        copy(v.begin(), v.end(), t.begin() + n + n + n);
        n <<= 1;
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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        vector<int> a(n);
        for(int &x: a)    cin >> x;
        bool flag = true;
        for(int x: a)
        {
            if(x != a[0])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "0\n";
            continue;
        }
        
        Segtree st(a);
        int beg = 1, end = n - 1, ans;
        auto possible = [&](int m)
        {
            int k = n - m;
            // cerr << m << " : ";
            int g = st.range_op(0, m + 1);
            for(int i = 1; i < n; i++) {
                if(st.range_op(i, i + m + 1)!= g)
                    return false;
            }
            // cerr << "true\n";
            return true;
        };
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(possible(mid))
                ans = mid, end = mid - 1;
            else
                beg = mid + 1;
        }
        cout << ans << '\n';
        // cerr << '\n';
    }
}