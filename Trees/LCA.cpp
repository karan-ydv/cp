#include <bits/stdc++.h>
using namespace std;
 
struct LCA {
    vector<int> height, euler, first, t;
	vector<bool> visited;
	int n, N;
 
    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n + 1);
		height[n] = 1 << 30;
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
		build();
    }
 
    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }
 
	int op(int i, int j) {
		if(height[i] < height[j])	return i;
		return j;
	}
 
	void build() {
		N = euler.size();
		t.resize(N << 1);
		copy(euler.begin(), euler.end(), t.begin() + N);
		for(int i = N - 1; i > 0; i--)
			t[i] = op(t[i << 1], t[i << 1|1]);
	}
 
	int range_min(int l, int r) {  // index of min on interval [l, r)
		int idx = n;
		for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if(l & 1)	idx = op(idx, t[l++]);
			if(r & 1)	idx = op(idx, t[--r]);
		}
		return idx;
	}
 
    int lca(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r)	swap(l, r); r++;
		return range_min(l, r);
    }
};
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++) {
		int m, x;	cin >> m;
		for(int j = 0; j < m; j++)
			cin >> x, adj[i].push_back(x);
	}
	LCA tree(adj);
	int q;	cin >> q;
	while(q--)
	{
		int v, w;	cin >> v >> w;
		cout << tree.lca(v, w) << '\n';
	}
} 