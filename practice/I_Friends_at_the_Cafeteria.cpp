#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	pair<int, int> a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
		a[i].first += a[i].second;
	}
	sort(a, a + n);
	deque<pair<int, int>> q;
	auto good = [&]() {
		if(q.empty())
			return true;
		return q.back().first - q.front().first <= m;
	};
	int ans = 0;
	for(int R = 0; R < n; R++) {
		q.push_back(a[R]);
		while(!good()) {
			q.pop_front();
		}
		ans = max(ans, (int)q.size());
	}
	cout << ans;
}