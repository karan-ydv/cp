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
		map<int, int> map;
		for(int i = 0; i < n; i++)
		{
			int x;	cin >> x;
			map[x]++;
		}
		priority_queue<int> pq;
		for(auto [x, f]: map)
			pq.push(f);
		
		while(pq.size() > 1)
		{
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			a--, b--;
			if(a) pq.push(a);
			if(b) pq.push(b);
		}
		int ans = pq.empty() ? 0 : pq.top();
		cout << ans << '\n';
	}
}