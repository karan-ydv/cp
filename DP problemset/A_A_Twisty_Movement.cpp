#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    Segtree(vector<int>& v) {
        n = v.size();
        t.resize(n << 1);
        copy(v.begin(), v.end(), t.begin() + n);
        build();
    }
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
        for(int i = 0; i < n; i++)
            cin >> t[n + i];
        build();
    }
    void build() {
        for(int i = n - 1; i > 0; i--)
            t[i] = min(t[i << 1], t[i << 1|1]);
    }
    int range_min(int l, int r) {  // min on interval [l, r)
        int res = INT32_MAX;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = min(res, t[l++]);
            if(r & 1) res = min(res, t[--r]);
        }
        return res;
    }
    void modify(int p, int value) {  // set value at position p
        for(t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = min(t[p], t[p^1]);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    int dp[n][2];
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] >= a[i - 1])
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = max(dp[i - 1][0]

        }
    }
}