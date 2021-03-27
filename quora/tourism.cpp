#include <bits/stdc++.h>
using namespace std;

struct LCA {
    vector<int> height, euler, first, t, sum;
	vector<bool> visited;
	int n, N;

    LCA(vector<vector<pair<int, int>>> &adj, vector<int> &a, int root = 0) {
        n = adj.size();
        height.resize(n + 1);
		height[n] = 1 << 30;
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
		sum.resize(n);
		sum[0] = 0;
        dfs(adj, root);
		build();
    }

    void dfs(vector<vector<pair<int, int>>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto [to, d]: adj[node]) {
            if (!visited[to]) {
				sum[to] = sum[node] + d;
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
	int path_sum(int u, int v) {
		int l = lca(u, v);
		int x = height[u] - sum[u] - height[l] + sum[l];	// u to LCA
		int y = sum[v] - sum[l];							// LCA to v
		return x + y;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	vector<int> a(n);
	for(int &x: a)	cin >> x;
	vector<vector<pair<int, int>>> adj(n);
	for(int i = 1; i < n; i++) {
		int u, v, t;	cin >> u >> v >> t;
		u--, v--;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}
	LCA tree(adj, a);
	int q;	cin >> q;
	while(q--)
	{
		int x, y;	cin >> x >> y;
		int ans = k * tree.path_sum(--x, --y);
		cout << ans << '\n';
	}
}