#include <bits/stdc++.h>
#define int long long
using namespace std;

#define f first
#define s second
typedef pair<int, int> pii;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n];	for(int &x: a)	cin >> x;
	vector<pii> v;
	int ans = 1;
	for(int i = 0; i < n;)
	{
		int end = a[i], j;
		for(j = i + 1; j < n; j++) {
			if(a[j] > end)
				end = a[j];
			else break;
		}
		v.emplace_back(i, j - 1);
		ans = max(ans, j - i);
		// cerr << i << ' ' << j - 1 << '\n';
		i = j;
	}
	int m = v.size();
	if(m > 1)	ans = max(ans, v[0].s - v[0].f + 2);
	for(int i = 1; i < m; i++)
	{
		if((v[i].f == v[i].s) or (v[i - 1].f == v[i - 1].s) or 
			(a[v[i].f] - a[v[i].f - 2]) > 1 or (a[v[i].f + 1] - a[v[i].f - 1]) > 1)
		{
			ans = max(ans, v[i].s - v[i].f + v[i - 1].s - v[i - 1].f + 2);
		}
		ans = max(ans, v[i].s - v[i].f + 2);
	}
	cout << ans;
}