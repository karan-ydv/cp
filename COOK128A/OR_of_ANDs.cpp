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
	int op(int a, int b) {
		return a | b;
	}
	void build() {
		for(int i = n - 1; i > 0; i--)
			t[i] = op(t[i << 1], t[i << 1|1]);
	}
	int range_op(int l, int r) {  // op on interval [l, r)
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res = op(res, t[l++]);
			if(r & 1) res = op(res, t[--r]);
		}
		return res;
	}
	void modify(int p, int value) {  // set value at position p
		for(t[p += n] = value; p > 1; p >>= 1)
			t[p >> 1] = op(t[p], t[p^1]);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, q;	cin >> n >> q;
		vector<int> v(n);
		for(int &x: v)	cin >> x;
		Segtree sg(v);
		cout << sg.range_op(0, n) << '\n';
		while(q--)
		{
			int x, val;	cin >> x >> val;
			x--;
			sg.modify(x, val);
			cout << sg.range_op(0, n) << '\n';
		}
	}
}