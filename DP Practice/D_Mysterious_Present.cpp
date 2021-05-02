#include <bits/stdc++.h>
#define int long long
using namespace std;

#define f first
#define s second
typedef pair<int, int> pii;
bool cmp(pii a, pii b)
{
	return a.f < b.f and a.s < b.s;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pii p;
	int n;	cin >> n >> p.f >> p.s;
	pair<pii, int> a[n]; int dp[n];
	for(int i = 0; i < n; i++)
	{
		a[i].s = i + 1;
		cin >> a[i].f.f >> a[i].f.s;
	}
	sort(a, a + n);
	for(int i = n - 1; i >= 0; i--)
	{
		dp[i] = 1;
		for(int j = i + 1; j < n; j++)
		if(cmp(a[i].f, a[j].f))
			dp[i] = max(dp[i], 1 + dp[j]);
	}
	int ans = 0, beg = -1;
	for(int i = 0; i < n; i++)
	{
		if(cmp(p, a[i].f) and ans < dp[i])
		{
			ans = dp[i];
			beg = i;
		}
	}
	cout << ans << '\n';
	while(beg != -1)
	{
		cout << a[beg].s << ' ';
		int i;
		for(i = beg; i < n; i++)
		if(dp[beg] == dp[i] + 1 and cmp(a[beg].f, a[i].f))
		{
			beg = i;	break;
		}
		if(i == n)	break;
	}
}