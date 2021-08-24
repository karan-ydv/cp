#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree
{
    int n;
    vector<int> t;
    Segtree(int n)
    {
        this->n = n;
        t.resize(n << 1);
        for (int i = 0; i < n; i++)
            cin >> t[n + i];
        build();
    }
    void build()
    {
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    int range_min(int l, int r)
    { // min on interval [l, r)
        int res = INT32_MAX;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = min(res, t[l++]);
            if (r & 1)
                res = min(res, t[--r]);
        }
        return res;
    }
    void modify(int p, int value)
    { // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = min(t[p], t[p ^ 1]);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;  cin >> n;
        Segtree st(n);
        int q;  cin >> q;
        while(q--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if(a == 1)
               st.modify(b - 1, c);
            else
                cout << st.range_min(b - 1, c) << '\n';
        }
    }
}