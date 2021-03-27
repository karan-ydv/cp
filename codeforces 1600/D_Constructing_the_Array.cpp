#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int a[n], x = 1;
		queue<tuple<int, int>> q;
		// priority_queue<tuple<int, int>> q;
		q.push({n, 0});
		while(!q.empty())
		{
			auto [m, i] = q.front(); q.pop();
			i = -i;
			if(m & 1) {
				a[i + m / 2] = x++;
				if(m / 2 > 0)
				{
					q.push({m / 2, -i});
					q.push({m / 2, -(i + m / 2 + 1)});
				}
			}
			else {
				a[i + m / 2 - 1] = x++;
				if(m == 2)
					q.push({1, -(i + 1)});
				else
				{
					q.push({m / 2, -(i + m / 2)});
					q.push({m / 2 - 1, - i});
				}
			}
		}
		for(auto x: a)	cout << x << ' ';	cout << '\n';
	}
}