#include <bits/stdc++.h>
using namespace std;

/* https://cp-algorithms.com/data_structures/segment_tree.html */

struct Vertex {
    Vertex *l, *r;
    int sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r || v == NULL)	return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int A[n];	for(int &b: A) cin >> b;

	// cordinate compression
	unordered_map<int, int> mp;
	vector<int> v(A, A + n);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i = 0; i < v.size(); i++)	mp[v[i]] = i;
	
	// persistent segtree
	vector<Vertex*> roots;
	int tl = 0, tr = v.size();
	roots.push_back(build(tl, tr));
	for (int i = 0; i < n; i++) {
		roots.push_back(update(roots.back(), tl, tr, mp[A[i]]));
	}
	int q; cin >> q;
	while(q--)
	{
		int i, j, k;	cin >> i >> j >> k;
		if(mp.count(k))	k = mp[k] + 1;
		else			k = upper_bound(v.begin(), v.end(), k) - v.begin();
		int ans = get_sum(roots[j], tl, tr, k, n - 1);
		if(i > 1)
		ans -= get_sum(roots[i - 1], tl, tr, k, n - 1);
		cout << ans << '\n';
	}
}