#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#define f first
#define s second

struct Segtree {
    int n;
    vector<int> t;
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
    }
    inline int op(int a, int b) {
        return a + b;
    }
    int range_sum(int l, int r) {  // min on interval [l, r)
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p) {  // invert value at position p
        for(t[p += n] ^= 1; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

const int N = 2e5+69;
int ans1[N], ans2[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    pair<int, int> a[n + n];
    for(int i = 0, j = 0; i < n; i++, j += 2)
    {
        cin >> a[j].f;
        cin >> a[j + 1].f;
        a[j].s = i;
        a[j + 1].s = i;
    }
    vector<int> last(n, -1);
    sort(a, a + n + n);
    Segtree s1(n << 1), s2(n << 1);
    int i = 0, prev = ;
    for(auto [val, x]: a) {
        cerr << x << ' ';} cerr << '\n';
    for(auto [val, x]: a) {
        cerr << val << ' ';
        if(last[x] != -1) {
            ans1[x] = s1.range_sum(last[x], i);
            ans2[x] = s2.range_sum(0, last[x]);
            s1.modify(last[x]);
            s2.modify(last[x]);
        }
        else {
            s2.modify(i);
            last[x] = i;
        }
        i++;
    }
    for(int i = 0; i < n; i++)
        cout << ans1[i] << ' '; cout << '\n';
    for(int i = 0; i < n; i++)
        cout << ans2[i] << ' ';
}