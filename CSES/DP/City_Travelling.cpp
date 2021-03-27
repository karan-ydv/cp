#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	vector<int> graph[n + 1];
	for(int i = 0; i < n; i++)
	{
		int u, v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(-u);
	}
	int q;	cin >> q;
	while(q--)
	{
		
	}
}