#include <bits/stdc++.h>
#define int long long
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
		int res = 1 << 30;
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
	int n, q;	cin >> n >> q;
	Segtree sg(n);
	while(q--)
	{
		int x, a, b;	cin >> x >> a >> b;
		if(--x)
			cout << sg.range_min(a - 1, b) << '\n';
		else
			sg.modify(a - 1, b);
	}
}