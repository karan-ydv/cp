#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+69;
pair<int, int> a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	int ans = 0, t = 0;
	for(int i = 0; i < n; i++)
	if(a[i].second >= t)
	{
		ans++;
		t = a[i].first;
	}
	cout << ans;
}