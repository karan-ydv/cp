#include <bits/stdc++.h>
#define int long long
using namespace std;

#define f first
#define s second

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;	cin >> T;
	while(T--)
	{
		int n, m, t;	cin >> n >> m >> t;
		int p[n];	pair<int, int> a[m];
		for(int &x: p)	cin >> x;
		partial_sum(p, p + n, p);
		for(auto &x: a)	cin >> x.s;
		for(auto &x: a)	cin >> x.f;
		sort(p, p + n);
		sort(a, a + m);
		int sum = 0;
		for(int i= 0; i < m / 2; i++)	sum += a[i].second;
		t -= sum;
		int ans = upper_bound(p, p + n, t) - p;
		cout << ans << '\n';
	}
}