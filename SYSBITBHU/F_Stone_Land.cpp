#include <bits/stdc++.h>
using namespace std;

int N;
struct SegTree
{
	vector<int> t;
	SegTree(int n) {
		N = 1;
		while(N < n)	N <<= 1;
		t.assign(2 * N, 0);
		for(int i = N; i < N + n; i++)	cin >> t[i];
		build();
	}
	SegTree(vector<int> &v)
	{
		N = 1;
		int n = v.size();
		while(N < n)	N <<= 1;
		t.resize(N << 1, 0);
		for(int i = N; i < N + n; i++)	t[i] = v[i - N];
		build();
	}
	void build()
	{
		for(int i = N - 1; i > 0; i--)
		t[i] = max(t[i << 1], t[i << 1|1]);
	}
	int range_max(int l, int r) {  // max value on interval [l, r)
		int res = -1;
		for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res = max(res, t[l++]);
			if(r & 1) res = max(res, t[--r]);
		}
		return res;
	}
	// returns idx >= l of first element >= x, 0 based indexing
	int first_above(int x, int l, int p = 1, int s = N) {
		if(t[p] < x or s <= l)	return -1;
		if((p << 1) >= 2 * N)
			return (t[p] >= x) - 1;
		int i = first_above(x, l, p << 1, s >> 1);
		if(i != -1)	return i;
		i = first_above(x, l - (s >> 1), p << 1 | 1, s >> 1);
		if(i == -1)	return -1;
		return (s >> 1) + i;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		SegTree sg(n);
		
		int dp[n];	dp[n - 1] = 0;
		for(int i = n - 2; i >= 0; i--)
		{
			int j = sg.first_above(sg.t[N + i] + 1, i + 1);
			if(j == -1)	dp[i] = 0;
			else		dp[i] = dp[j] + 1;
		}
		while(m--)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			if(a == b)	cout << dp[a] << '\n';
			else
			{
				if(a > b)		swap(a, b);
				int mx = sg.range_max(a, b);
				int j = sg.first_above(mx + 1, b);
				if(j == -1)	cout << "0\n";
				else if(j != b)
					cout << dp[j] + 1 << '\n';
				else
					cout << dp[j] << '\n';
			}
		}
	}
}