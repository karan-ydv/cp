#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#define f first
#define s second
const int N = 1e5 + 69;
pair<int, int> a[N];
int dp[N];

struct Segtree
{
    int n;
    vector<int> t;
    Segtree(int n)
    {
        this->n = n;
        t.resize(n << 1, 1e18);
        t[n] = 0;
        build();
    }
    void build()
    {
        for (int i = n - 1; i > 0; i--)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    int range_min(int l, int r)
    { // min on interval [l, r)
        int res = 1e18;
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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i].f >> a[i].s;
        sort(a, a + m);
        for (int i = 1; i <= n; i++)
            dp[i] = 1e18;
        Segtree st(n + 1);
        for (int i = 1, j = 0; i <= n; i++)
        {
            while (j < m and a[j].f == i)
            {
                int r = a[j].s;
                int mn = st.range_min(i - 1, r);
                if (dp[r] > mn + r - a[j].f + 1)
                {
                    dp[r] = mn + r - a[j].f + 1;
                    st.modify(r, mn + r - a[j].f + 1);
                }
                j++;
            }
        }
        if (dp[n] == 1e18)
            dp[n] = -1;
        cout << dp[n] << '\n';
    }
}