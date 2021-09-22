#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int N;
struct SegTree
{
    vector<int> t;
    SegTree(vector<int> &v)
    {
        N = 1;
        int n = v.size();
        while(N < n)	N <<= 1;
        t.resize(N << 1, 0);
        for(int i = N; i < N + n; i++)	t[i] = v[i - N];
        build();
    }
    void build()
    {
        for(int i = N - 1; i > 0; i--)
        t[i] = max(t[i << 1], t[i << 1|1]);
    }
    int range_max(int l, int r) {  // max value on interval [l, r)
        int res = -1;
        for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = max(res, t[l++]);
            if(r & 1) res = max(res, t[--r]);
        }
        return res;
    }
    // returns idx >= l of first element >= x, 0 based indexing
    int first_above(int x, int l, int p = 1, int s = N) {
        if(t[p] < x or s <= l)	return -1;
        if((p << 1) >= 2 * N)
            return (t[p] >= x) - 1;
        int i = first_above(x, l, p << 1, s >> 1);
        if(i != -1)	return i;
        i = first_above(x, l - (s >> 1), p << 1 | 1, s >> 1);
        if(i == -1)	return -1;
        return (s >> 1) + i;
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
        vector<int> v(n), a;
        for(int &x: v)  cin >> x;
        reverse(v.begin(), v.end());
        SegTree st(v);
        int ans = 0, i = 0;
        while(i != n - 1)
        {
            ans++;
            int x = v[i];
            while(v[i] == x)
            {
                i = st.first_above(v[i], i + 1);
                if(i == -1 or i == n - 1)
                    break;
            }
            if(i == -1)
            {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
}