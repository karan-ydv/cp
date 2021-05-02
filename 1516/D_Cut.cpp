#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int LOG = 18;
int spf[N];	// smallest prime factor
void sieve()
{
	iota(spf, spf + N, 0);
	for(int i = 4; i <= N; i += 2)  spf[i] = 2;
	for(int i = 3; i * i <= N; i += 2)
	{
		if(spf[i] == i)	for(int j = i * i; j < N; j += i)
		if(spf[j] == j)	spf[j] = i;
	}
}
vector<pair<int, int>> factors(int n) {
	vector<pair<int, int>> f;
	while(n != 1)
	{
		int p = spf[n], c = 0;
		while(spf[n] == p)
			c++, n /= p;
		f.emplace_back(p, c);
	}
	return f;
}

int go[N], nxt[N];
int up[N][LOG];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();

	int n, q;	cin >> n >> q;
	fill_n(nxt, N, n);
	int a[n];	for(int &x: a)	cin >> x;

	go[n] = n;
	for(int i = n - 1; i >= 0; i--)
	{
		int r = n;
		for(auto [x, y]: factors(a[i]))
		{
			r = min(r, nxt[x]);
			nxt[x] = i;
		}
		go[i] = min(go[i + 1], r);
	}
	
	for(int i = 0; i <= n; i++)	up[i][0] = go[i];
	for(int j = 1; j < LOG; j++)
	for(int i = 0; i <= n; i++)
		up[i][j] = up[up[i][j - 1]][j - 1];

	while(q--)
	{
		int l, r;	cin >> l >> r;	l--;
		int ans = 1;
		for(int i = LOG - 1; i >= 0; i--)
		if(up[l][i] < r)
		{
			ans += 1 << i;
			l = up[l][i];
		}
		cout << ans << '\n';
	}
}