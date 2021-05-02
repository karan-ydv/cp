#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	pair<int, int> a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i].first, a[i].second = i;
	sort(a, a + n);
	int idx = -1, ans = 1;
	for(int i = 0; i < n; i++)
	{
		if(a[i].second < idx)	ans++;
		idx = a[i].second;
	}
	cout << ans;
}