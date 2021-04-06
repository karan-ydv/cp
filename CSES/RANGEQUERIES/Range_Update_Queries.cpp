#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Segtree
{
	int N = 1, n;
	vector<int> t, d;
	Segtree(vector<int>& v) {
		n = v.size();
		calculateN();
		d.resize(N << 1);
		t.resize(N << 1);
		copy(v.begin(), v.end(), t.begin() + N);
		build();
	}
	Segtree(int n) {
		this -> n = n;
		calculateN();
		d.resize(N << 1);
		t.resize(N << 1);
		for(int i = 0; i < n; i++)	cin >> t[N + i];
		build();
	}
	void calculateN() {
		while(N < n) N <<= 1;
	}
	void build() {
		for(int i = N - 1; i > 0; i--)
			t[i] = t[i << 1] + t[i << 1|1];
	}
	int L, R, V;
	void increment2(int p, int lx, int rx) {
		if(L == R)	return;
		if(lx >= R || rx <= L)	return;
		if(lx >= L && rx <= R)	return t[p] += V * (rx - lx), d[p] += V, void();
		int m = (lx + rx) / 2;
		increment2(p << 1, lx, m);
		increment2(p << 1|1, m, rx);
		t[p] = t[p << 1] + t[p << 1|1] + d[p] * (rx - lx);
	}

	int range_sum(int p, int lx, int rx) {
		if(lx >= R or rx <= L)		return 0;
		if(lx >= L and rx <= R)		return t[p];
		int m = (lx + rx) / 2;
		return range_sum(p << 1, lx, m) + range_sum(p << 1|1, m, rx) + d[p] * (min(rx, R) - max(lx, L));
	}
	void increment(int l, int r, int v) {	// add v to interval [l, r)
		L = l, R = r, V = v;
		increment2(1, 0, N);
	}
	int range_sum(int l, int r) {			// sum of interval [l, r)
		L = l, R = r;
		return range_sum(1, 0, N);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;	cin >> n >> q;
	Segtree sg(n);
	while(q--)
	{
		int op;	cin >> op;
		if(op == 1)
		{
			int a, b, u;	cin >> a >> b >> u;
			sg.increment(a - 1, b, u);
		}
		else
		{
			int k;	cin >> k;
			cout << sg.range_sum(k - 1, k) << '\n';
		}
	}
}