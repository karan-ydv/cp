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
    int range_sum(int l, int r) {  // sum on interval [l, r)
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res += t[l++];
            if(r & 1) res += t[--r];
        }
        return res;
    }
    void modify(int p, int value) {  // set value at position p
        for(t[p += n] += value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p^1];
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
        tuple<int, int, int> tc[n];
        vector<pair<int, int>> v;

        for(auto &[a, b, c]: tc)
        {
            cin >> a >> b >> c;
            v.emplace_back(a, b);
        }

        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        vector<pair<int, int>> w(v.begin(), v.end());
        for(auto &[x, y]: w)    swap(x, y);
        sort(w.begin(), w.end());
        
        Segtree sgx(v.size()), sgy(v.size());
        int sum = 0;
        for(auto &[a, b, c]: tc)
        {
            sum += c;
            pair<int, int> p = {a, -2e9};
            pair<int, int> q = {b, -2e9};
            int idx = upper_bound(v.begin(), v.end(), p) - v.begin();
            int idy = upper_bound(w.begin(), w.end(), q) - w.begin();
            int bc = sgx.range_sum(0, idx);
            int cd = sgy.range_sum(0, idy);
            int ans = sum - bc - cd;
            cout << ans << '\n';
            sgx.modify(idx, c);
            sgy.modify(idy, c);
        }
    }
}