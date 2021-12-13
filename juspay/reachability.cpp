#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> item;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;	cin >> x;
    }
	int e;  cin >> e;
    unordered_map<int, int> dist;
    unordered_map<int, vector<item>> adj;
	while(e --> 0)
	{
		int u, v, w;
        cin >> u >> v >> w;
        dist[u] = dist[v] = 1e9;
		adj[u].emplace_back(v, w);
	}
	int a, b;	cin >> a >> b;
    function<void(int)> Dijkstra = [&](int a)
    {
        dist[a] = 0;
    	unordered_map<int, bool> vis;
        priority_queue<item, vector<item>, greater<item>> q;
        q.push({0, a});
        int d, u, v, w;
        while(!q.empty())
        {
            tie(d, u) = q.top();
            vis[u] = true;
            q.pop();
            if(dist[u] < d)    continue;
            for(item p: adj[u]) {
                tie(v, w) = p;
                if(vis[v])    continue;
                if(d + w < dist[v]) {
                    dist[v] =  d + w;
                    q.push({d + w, v});
                }
            }
        }
    };
    Dijkstra(a);
    if(dist[b] >= 1e9)
        dist[b] = -1;
    cout << dist[b];
}