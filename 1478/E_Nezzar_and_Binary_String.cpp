#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, q;	cin >> n >> q;
		string s, f;	cin >> s >> f;

		int d[n]; d[0] = s[0] != f[0];
		for(int i = 1; i < n; i++) {
			d[i] = d[i - 1] + (s[i] != f[i]);
		}
		segtree st = segtree(n);
		while(q--)
		{
			int l, r;	cin >> l >> r;
			st.update(l - 1, r);
		}
	}
}