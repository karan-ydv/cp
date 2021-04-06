#include <bits/stdc++.h>
#define int long long
using namespace std;

int N = 1;
vector<int> t, d;

int L, R, V;
void increment(int p = 1, int lx = 0, int rx = N) {
	if(lx >= R || rx <= L)	return;
	if(lx >= L && rx <= R)	return t[p] += V * (rx - lx), d[p] += V, void();
	int m = (lx + rx) / 2;
	increment(p << 1, lx, m);
	increment(p << 1|1, m, rx);
	t[p] = t[p << 1] + t[p << 1|1] + d[p] * (rx - lx);
}

int range_sum(int p = 1, int lx = 0, int rx = N) {
	if(lx >= R or rx <= L)		return 0;
	if(lx >= L and rx <= R)		return t[p];
	int m = (lx + rx) / 2;
	return range_sum(p << 1, lx, m) + range_sum(p << 1|1, m, rx) + d[p] * (min(rx, R) - max(lx, L));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(N < n)	N <<= 1;
	t.resize(N << 1);
	d.resize(N << 1);

	for(int i = 0; i < n; i++)	cin >> t[N + i];
	for(int i = N; i > 0; i--)	t[i] = t[i << 1] + t[i << 1|1];
	while(m--)
	{
		int op, a, b, c;
		cin >> op >> a;
		if(--op) L = a - 1, R = a, cout << range_sum() << '\n';
		else	cin >> b >> c, L = a - 1, R = b, V = c, increment();
	}
}