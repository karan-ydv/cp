#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++)
	{
		int x, y;	cin >> x >> y;
		v.emplace_back(x, 1);
		v.emplace_back(y, -1);
	}
	sort(v.begin(), v.end());
	int sum = 0, ans = 0;
	for(auto [x, y]: v)
	{
		sum += y;
		ans = max(ans, sum);
	}
	cout << ans;
}