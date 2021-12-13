#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int modexp(int a, int n){
    int p = 1;
    for(; n; n >>= 1, (a *= a) %= mod)
        if(n & 1)	(p *= a) %= mod;
    return p;
}

struct LCA {
	int l, timer;
	vector<vector<int>> AN;
	vector<int> tin, tout, h;
 
	LCA(vector<vector<int>>& adj) {
		int n = adj.size();
		l = (int) ceil(log2(n));
		AN.resize(n, vector<int>(l + 1));
        h.resize(n);
		tin.resize(n);
		tout.resize(n);
		dfs(adj, 0, 0);
	}
	void dfs(vector<vector<int>>& adj, int u, int d) {
		tin[u] = ++timer;
        h[u] = d;
		for (int i = 1; i <= l; ++i) {
			AN[u][i] = AN[AN[u][i - 1]][i - 1];
		}
 
		for (auto v: adj[u]) {
			AN[v][0] = u;
			dfs(adj, v, d + 1);
		}
		tout[u] = ++timer;
	}
 
	bool is_ancestor(int u, int v) {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}
 
	int lca(int u, int v)
	{
		if (is_ancestor(u, v))	return u;
		if (is_ancestor(v, u))	return v;
        stack<int> stack;
		for (int i = l; i >= 0; --i) {
			if (!is_ancestor(AN[u][i], v))
				u = AN[u][i];
		}
		return AN[u][0];
	}
};

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<int> A, B, pro, pro2;
    vector<int> par;
    int V;
    Graph(int v) : V(v)
    {
        adj.resize(v);
        A.resize(v);
        B.resize(v);
        pro.resize(v);
        pro2.resize(v);
        par.resize(v);        

        int inv = modexp(1e6, mod - 2);
        cin >> pro[0]; (pro[0] *= inv) %= mod;
        for(int i = 1; i < v; i++)
        {
            cin >> par[i] >> A[i] >> B[i];
            adj[--par[i]].emplace_back(i);
            (A[i] *= inv) %= mod;
            (B[i] *= inv) %= mod;
        }
        for(int x: adj[0])  DFS(x, 1);
        pro.swap(pro2);
        for(int x: adj[0])  DFS(x, 0);
        pro.swap(pro2);
        for(int i = 1; i < v; i++) {
            (pro[i] *= pro[0]) %= mod;
            (pro[i] += (mod + 1 - pro[0]) * pro2[i] % mod) %= mod;
        }
    }   
    void DFS(int u, int p)
    {
        pro[u] = (A[u] * p % mod + B[u] * (mod + 1 - p) % mod) % mod;
        for(auto v: adj[u]) DFS(v, pro[u]);
    }
    int dfs(int u, int w, bool f)
    {
        if(u == w)  return f;
        int p = dfs(par[u], w, f);
        return (p * A[u] % mod + (mod + 1 - p) * B[u] % mod) % mod;
    }
    void solve(int q)
    {
        LCA Lca(adj);
        while(q--)
        {
            int u, v; cin >> u >> v; u--, v--;
            int w = Lca.lca(u, v);
            int a = pro[w] * dfs(u, w, 1) % mod * dfs(v, w, 1) % mod;
            int b = (mod + 1 - pro[w]) * dfs(u, w, 0) % mod * dfs(v, w, 0) % mod;
            cout << (a + b) % mod << ' ';
        }
        cout << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n, q;   cin >> n >> q;
        Graph g(n);  g.solve(q);
    }
}