#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Vertex {
    Vertex *l, *r;
    int mx;
    Vertex(int val) : l(nullptr), r(nullptr), mx(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), mx(0) {
        if (l) mx = max(mx, l->mx);
        if (r) mx = max(mx, r->mx);
    }
};

int get_max(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r || v == NULL)	return 0;
    if (l == tl && tr == r)
        return v->mx;
    int tm = (tl + tr) / 2;
    return max(get_max(v->l, tl, tm, l, min(r, tm)),
               get_max(v->r, tm+1, tr, max(l, tm+1), r));
}
 
Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}
 
Vertex* update(Vertex* v, int tl, int tr, int pos, int val) {
    if (tl == tr)
        return new Vertex(max(v->mx, val));
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, val));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n], k[n], dp[n];
        for(int &x: a)  cin >> x;
        for(int &x: k)  cin >> x;

        // persistent segtree
    	vector<Vertex*> roots;
    	int tl = 0, tr = n + n;
    	roots.push_back(build(tl, tr));

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int j = max(0ll, i - k[i]);
            dp[i] = a[i] + get_max(roots[j], tl, tr, 0, i - 1);
            // clog << dp[i] << ' ';
            roots.push_back(update(roots.back(), tl, tr, i + k[i], dp[i]));
            ans = max(ans, dp[i]);
        }
        // clog << '\n';
        cout << ans << '\n';
    }
}