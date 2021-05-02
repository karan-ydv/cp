#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
vector<int> f[N];
int freq(int x, int l, int r) {
	return lower_bound(f[x].begin(), f[x].end(), r) - 
			lower_bound(f[x].begin(), f[x].end(), l);
}

struct Segtree
{
	typedef int node;
	int n, N;
	vector<node> t;
	vector<int> L, R;
	Segtree(vector<int>& v)
	{
		n = v.size();
		N = 1;
		while(N < n) N <<= 1;
		t.resize(N << 1);
		L.resize(N << 1);
		R.resize(N << 1);
		copy(v.begin(), v.end(), t.begin() + N);
		build();
	}
	node combine(int a, int b, int l, int r)
	{
		if(a == 0 or b == 0)	return a + b;
		int fa = freq(a, l, r);
		int fb = freq(b, l, r);
		return fa > fb ? a : b;
	}
	void build()
	{
		iota(L.begin() + N, L.end(), 0);
		iota(R.begin() + N, R.end(), 1);
		for(int i = N - 1; i > 0; i--)
		{
			L[i] = L[i << 1], R[i] = R[i << 1|1];
			t[i] = combine(t[i << 1], t[i << 1|1], L[i], R[i]);
		}
	}
	int range_op(int l, int r)	// op on interval [l, r)
	{
		int x = l, y = r;
		int resl = 0, resr = 0;
		for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {resl = combine(resl, t[l], x, R[l]); l++;}
			if(r & 1) {--r; resr = combine(t[r], resr, L[r], y);}
		}
		int fl = freq(resl, x, y);
		int fr = freq(resr, x, y);
		return max(fl, fr);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> A(n);
	for(int i = 0; i < n; i++)	
	{
		cin >> A[i];	
		f[A[i]].emplace_back(i);
	}
	Segtree sg(A);
	while(q--)
	{
		int l, r;	cin >> l >> r;
		int f = sg.range_op(--l, r);
		int m = r  - l;
		if(f > (m + 1) / 2)
			cout << 2 * f - m << '\n';
		else
			cout << "1\n";
	}
}