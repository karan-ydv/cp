#include <bits/stdc++.h>
#define int long long
using namespace std;


struct Graph {
	// topological sort
	typedef int item;
	typedef vector<vector<item>> vv;
	stack<item> ordering;
	vector<bool> visited;
	vector<int> color;
	vv adj;	int n;
	Graph(int v, int e) {
		n = v;
		adj.resize(v);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			u--, v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	Graph(vv &adjlist)
	{
		adj = adjlist;
		n = adj.size();
		color.resize(n);
		visited.resize(n);
	}
	bool checkcycle(int u)
	{
		color[u] = 1;
		for(int v: adj[u])
		{
			if(color[v] == 0)
			{
				if(checkcycle(v)) return true;
			}
			else if(color[v] == 1) return true;
		}
		color[u] = 2;
		return false;
	}
	void DFS(int u = 0, int p = -1)
	{
		visited[u] = 1;
		for(auto v: adj[u])
		if(!visited[v])
		{
			DFS(v, u);
		}
		ordering.push(u);
	}
	bool topsort()
	{
		for(int i = 0; i < n; i++) {
			if(color[i] == 0 and checkcycle(i))
				return false;
		}
		for(int i = 0; i < n; i++) {
			if(!visited[i]) {
				DFS(i, -1);
			}
		}
		return true;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;	cin >> n;
	string s[n];	for(string &x: s)	cin >> x;
	for(int i = 1; i < n; i++)
	{
		if(s[i].length() < s[i - 1].length())
			if(s[i] == s[i - 1].substr(0, s[i].length()))
				return cout << "Impossible", 0;
	}
	vector<vector<int>> v(26);
	for(int i = 1; i < n; i++)
	{
		int m = min(s[i].length(), s[i - 1].length());
		for(int j = 0; j < m; j++)
		if(s[i][j] != s[i - 1][j])
		{
			v[s[i - 1][j] - 'a'].emplace_back(s[i][j] - 'a');
			break;
		}
	}

	Graph g(v);
	if(!g.topsort())	cout << "Impossible\n";
	else
	{
		while(!g.ordering.empty())
		{
			cout << char('a' + g.ordering.top());
			g.ordering.pop();
		}
	}
}