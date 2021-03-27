#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef tuple<int, int, int> ti;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, k, b;	cin >> n >> k >> b;
		priority_queue<ti> q;
		for(int i = 1; i <= n; i++) {
			int x;	cin >> x;
			q.push({x, -i, 0});
		}
		int time = 0, sum = 0;
		vector<int> v;
		while(!q.empty() and time < k)
		{
			auto [x, y, z] = q.top();
			q.pop();
			if(z < b and x != 0) {
				// cout << x << '\n';
				sum += (x + 2) / 3;
				x -= (x + 2) / 3;
				z++;
				q.push({x, y, z});
				v.emplace_back(-y);
				time ++;
			}
		}
		cout << sum << ' ' << time << '\n';
		for(auto i: v)	cout << i << ' ';
		cout << '\n';
	}
}