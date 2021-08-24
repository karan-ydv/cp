#include <bits/stdc++.h>
#define int int64_t
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
        for(t[p += n] = 1; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; int n;
    cin >> n >> s;

    queue<int> q[26];
    for(int i = 0; i < n; i++)
        q[s[i] - 'a'].push(i);

    int a[n] = {};
    reverse(s.begin(), s.end());
    for(int i = 0; i < n; i++) 
    {
        a[q[s[i] - 'a'].front()] = i + 1;
        q[s[i] - 'a'].pop();
    }

    Segtree st(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        st.modify(a[i] - 1);
        ans += st.range_sum(a[i], n);
    }
    cout << ans;
}