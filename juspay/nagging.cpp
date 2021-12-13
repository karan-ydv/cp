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
	int e;  cin >> e;
    unordered_map<int, vector<int>> adj, fol;
	while(e --> 0)
	{
		int u, v;
        cin >> u >> v;
		adj[u].emplace_back(v);
        fol[v].emplace_back(u);
	}

    // for(auto &[x, v]: adj) {
    //     cerr << x << " : ";
    //     for(int y: v)   cerr << y << ' ';
    //     cerr << '\n';
    // }

	int a, b;	cin >> b >> a;
    unordered_set<int> children;
    for(int x: fol[a]) {
        children.insert(x);
    }
    // for(int x: children)    cerr << x << ' ';
    // cerr << '\n';
    unordered_set<int> ans;
    unordered_map<int, bool> vis;
    function<void(int)> dfs = [&](int u)
	{
		vis[u] = true;
        if(children.count(u)) {
            ans.insert(u);
            return;
        }
        for(int v: adj[u]) if(!vis[v]) dfs(v);
	};
    for(int x: adj[b]) dfs(x);
    if(children.count(b))
        ans.insert(b);
    for(int x: fol[a]) {
        if(ans.count(x))
            cout << x << ' ';
    }
}