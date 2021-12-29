#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;	cin >> x;
    }
    unordered_map<int, vector<int>> adj;
	int e;  cin >> e;
	while(e --> 0)
	{
		int u, v;	cin >> u >> v;
		adj[u].emplace_back(v);
	}
	int a, b;	cin >> a >> b;
	unordered_map<int, bool> vis;
    function<bool(int)> dfs = [&](int u)
	{
		vis[u] = true;
		if(u == b) return true;
		for(int v: adj[u]) if(!vis[v])
			if(dfs(v))	return true;
		return false;
	};
	cout << dfs(a);
}