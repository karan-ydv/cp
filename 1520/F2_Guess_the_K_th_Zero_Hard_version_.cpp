#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

struct Segtree {
    int n;
    vector<int> t;

    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
        fill_n(t.begin() + n, n, -1);
    }

    void increase(int l, int r, int value) {    // add value to [l, r)
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) t[l++] += value;
        if (r&1) t[--r] += value;
      }
    }

    int query(int p) {  // query value at [p]
      int res = 0;
      for (p += n; p > 0; p >>= 1) res += t[p];
      return res;
    }
};

Segtree st(N);

int cnt = 0;
int query(int l, int r)
{
    if(st.t[N + r] != -1)
    {
        return st.query(r);
    }
    assert(cnt < 6e4);
    ++cnt;
    cout << "? " << l << ' ' << r << endl;
    int x;  cin >> x;
    assert(x != -1);
    st.t[N + r] = 0;
    st.t[N + r] = x - st.query(r);
    return x;
}
void output(int ans)
{
    cout << "! " << ans << endl;
    st.increase(ans, N, 1);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;   cin >> n >> t;
    while(t--)
    {
        int k;	cin >> k;
        int beg = 1, end = n, ans;
        while(beg <= end)
        {
            int mid = (beg + end) >> 1;
            int x = mid - query(1, mid);
            if(x >= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else    beg = mid + 1;
        }
        output(ans);
    }
}