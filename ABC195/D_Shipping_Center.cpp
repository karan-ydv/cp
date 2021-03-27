#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;	cin >> n >> m >> q;
	pair<int, int> vw[n];
	int x[m];
	for(int i = 0; i < n; i++) {
		cin >> vw[i].second >> vw[i].first;
	}
	sort(vw, vw + n, greater<pair<int, int>>());
	for(int &a: x)	cin >> a;
	auto knapsack = [&](vector<int> &boxes) {
		int k = boxes.size();
		vector<bool> taken(k, false);
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < k; j++) {
				if(!taken[j] and vw[i].second <= boxes[j]) {
					taken[j] = true;
					ans += vw[i].first;
					break;
				}
			}
		}
		return ans;
	};
	while(q--)
	{
		int l, r;	cin >> l >> r;
		l--, r--;
		vector<int> boxes;
		for(int i = 0; i < m; i++) {
			if(i < l or i > r)
			boxes.emplace_back(x[i]);
		}
		sort(boxes.begin(), boxes.end());
		cout << knapsack(boxes) << '\n';
	}
}