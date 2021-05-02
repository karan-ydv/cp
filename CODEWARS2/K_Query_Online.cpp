#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    Vertex *l, *r;
    int sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

struct PersistentSegtree
{
	const int N = 3e4+5;
	vector<Vertex*> roots;
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
	PersistentSegtree(vector<int> &v)
	{
		roots.emplace_back(build(0, N));
		for(int i = 0; i < v.size(); i++) {
			roots.emplace_back(update(roots[i], 0, N, v[i]));
		}
	}
	int get_sum(Vertex* v, int tl, int tr, int l, int r) {
		if (l > r)
			return 0;
		if (l == tl && tr == r)
			return v->sum;
		int tm = (tl + tr) / 2;
		return get_sum(v->l, tl, tm, l, min(r, tm))
			+ get_sum(v->r, tm+1, tr, max(l, tm+1), r);
	}
	// number of v such that x <= v <= y in range [0, R)
	int get_sum(int x, int y, int R) {
		if(x >= N or y < 0)	return 0;
		x = max(0, x), y = min(y, N - 1);
		return get_sum(roots[R], 0, N, x, y);
	}
	int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
		if (tl == tr)
			return tl;
		int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
		if (left_count >= k)
			return find_kth(vl->l, vr->l, tl, tm, k);
		return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
	}
	// kth (1..k) smallest / sorted in [l, r)	(0..l, 0..r)
	int kthsmallest(int k, int l, int r) {
		return find_kth(roots[l], roots[r], 0, N, k);
	}
	// frequency of x in [l, r)	(0...l, 0...r)
	int freq(int x, int l, int r) {
		return get_sum(roots[r], 0, N, x, x) - get_sum(roots[l], 0, N, x, x);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;	cin >> n;
	int A[n];	for(int &x: A)	cin >> x;
	// cordinate compression
	unordered_map<int, int> mp;
	vector<int> v(A, A + n);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i = 0; i < v.size(); i++)	mp[v[i]] = i;

	vector<int> w(n);
	for(int i = 0; i < n; i++)	w[i] = mp[A[i]];
	PersistentSegtree st(w);

	int q, ans = 0;	cin >> q;
	while(q--)
	{
		int a, b, c;	cin >> a >> b >> c;
		int i = a ^ ans;
		int j = b ^ ans;
		int k = c ^ ans;
		if(i < 1)	i = 1;
		if(j > n)	j = n;

		if(i > j)	ans = 0;
		else
		{
			// cerr << i << ' ' << j << ' ' << k << '\n';
			k = upper_bound(v.begin(), v.end(), k) - v.begin();
			if(k == v.size())
				ans = 0;
			else
			{
				ans = st.get_sum(k, 1e9, j) - st.get_sum(k, 1e9, i - 1);
			}
		}
		cout << ans << '\n';
	}

}