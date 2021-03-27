#include <bits/stdc++.h>
#define int long long
using namespace std;

struct segtree {
	int N, n;
	vector<int> t;
	segtree(vector<int>& v) {
		n = v.size();
		N = 1;
		while(N < n)	N <<= 1;
		t.resize(2 * N);
		for(int i = 0; i < n; i++) {
			t[N + i] = v[i];
		}
		for(int i = N - 1; i > 0; i--) {
			t[i] = max(t[i << 1], t[i << 1|1]);
		}
	}
	int first_above(int x) {
		int i = 0, s = N >> 1;
		for(int p = 2; p < 2 * N; p <<= 1, s >>= 1) {
			if(t[p] < x)	p++, i += s;
		}
		if(t[N + i] < x)	i = -1;
		return i;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, m;	cin >> n >> m;
		int a[n]; for(int &x: a)	cin >> x;
		vector<int> pref(n);
		pref[0] = a[0];
		for(int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + a[i];
		}
		segtree sg(pref);
		while(m--)
		{
			int x;	cin >> x;
			int ans = sg.first_above(x);
			if(ans == -1 and pref[n - 1] > 0 and x > pref[n - 1])
			{
				int mx = sg.t[1];
				if(x > mx)
				{
					ans = n * ((x - mx) / pref[n - 1]);
					x -= (x - mx) / pref[n - 1] * pref[n - 1];
				}
				int j = sg.first_above(x);;
				while(j == -1)
				{
					x -= pref[n - 1];
					ans += n;
					j = sg.first_above(x);
				}
				ans += j;
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}