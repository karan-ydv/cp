#include <bits/stdc++.h>
using namespace std;

const int N = 26;
typedef bitset<N> node;

struct Segtree {
    int n;
    string s;
    vector<node> t;
    Segtree() {
        cin >> s;
        n = (int) s.size();
        t.resize(n << 1);
        for(int i = 0; i < n; i++)
            t[n + i][s[i] - 'a'] = 1;
        for(int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] | t[i << 1|1];
    }
    int range_query(int l, int r) {  // query on interval [l, r)
        node res;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res |= t[l++];
            if(r & 1) res |= t[--r];
        }
        return (int) res.count();
    }
    void modify(int p, char value) {  // set value at position p
        t[p + n][s[p] - 'a'] = 0;
        s[p] = value;
        for(t[p += n][value - 'a'] = 1; p > 1; p >>= 1)
            t[p >> 1] = t[p] | t[p^1];
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
        int x;  cin >> x;
        if(x == 1)
        {
            int p; char c; 
            cin >> p >> c;
            st.modify(p - 1, c);
        }
        else
        {
            int l, r;   cin >> l >> r;
            cout << st.range_query(--l, r) << '\n';
        }
    }

}