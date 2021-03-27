#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		set<int> s1, s2;
		priority_queue<pii, vector<pii>, greater<pii>> q;
		int x; cin >> x;
		for(int i = 2; i <= n; i++) {
			int v;	cin >> v;
			q.push({v, i});
		}
		vector<tuple<int, int, int>> op;
		while(!q.empty())
		{
			auto [mn, j] = q.top();
			q.pop();
			if(mn <= x)
			{
				x += mn;
				op.emplace_back(j, 1, mn);
			}
			else
			{
				if(q.empty()) {
					q.push({mn, j});
					break;
				}
				auto [mn2, k] = q.top();
				q.pop();
				int y = mn - x;
				op.emplace_back(j, k, y);
				op.emplace_back(j, 1, x);
				x += x;
				mn2 += y;
				q.push({mn2, k});
			}
		}
		if(q.empty())
		{
			cout << op.size() << '\n';
			for(auto [p, q, x]: op) {
				cout << p << ' ' << q << ' ' << x << '\n';
			}
		}
		else	cout << "-1\n";
	}
}