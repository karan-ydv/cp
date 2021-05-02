#include <bits/stdc++.h>
#define int long long
using namespace std;

int kadane(vector<int> &v)
{
	int sum = 0, mx = 0;
	for(int x: v)
	{
		sum += x;
		mx = max(mx, sum);
		if(sum < 0)	sum = 0;
	}
	return mx;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n];	for(int &x: a)	cin >> x;
		int ans = 0;
		vector<int> b, c;
		for(int i = 0; i < n; i++)			if(!(i & 1)) ans += a[i];
		for(int i = 1; i < n; i += 2)		b.emplace_back(a[i] - a[i - 1]);
		for(int i = 1; i < n - 1; i += 2)	c.emplace_back(a[i] - a[i + 1]);
		ans += max(kadane(b), kadane(c));
		cout << ans << '\n';
	}
}