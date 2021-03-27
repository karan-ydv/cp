#include <bits/stdc++.h>
#define int long long
using namespace std;

struct LCA {
    vector<int> height, euler, first, t, subsize;
    vector<int> segtree;
	int n, N;
 
    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n + 1);
		height[n] = 1 << 30;
        first.resize(n);
        subsize.resize(n);
        euler.reserve(n * 2);
        dfs(adj, root);
		build();
		build2();
    }
 
    int dfs(vector<vector<int>> &adj, int node, int h = 0) {
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        subsize[node] = 1;
        for (auto to : adj[node]) {
            subsize[node] += dfs(adj, to, h + 1);
            euler.push_back(node);
        }
        return subsize[node];
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
		if(u == -1)	return v;
		if(v == -1)	return u;
        int l = first[u], r = first[v];
        if (l > r)	swap(l, r); r++;
		return range_min(l, r);
    }
    void build2()
    {
		segtree.resize(n << 1);
        for(int i = n; i < 2 * n; i++) {
            if(subsize[i - n] == 1)
                segtree[i] = i - n;
            else
                segtree[i] = -1;
        }
        for(int i = n - 1; i > 0; i--)
            segtree[i] = lca(segtree[i << 1], segtree[i << 1 | 1]);
    }
	int query(int l, int r) {  // index of min on interval [l, r)
		int ans = -1;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)	ans = lca(segtree[l++], ans);
			if(r & 1)	ans = lca(segtree[--r], ans);
		}
		return ans;
	}
};

void solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size() + 1;
    vector<vector<int>> childs(n);
    for(int i = 0; i < n - 1; i++) {
        childs[A[i] - 1].emplace_back(i + 1);
    }
	for(int i = 0; i < n; i++) {
		cout << '\n';
	}
    LCA tree(childs);
    
    vector<int> queries;
    for(auto& v: B) {
        int L = v[0], R = v[1];
        int ans = tree.query(L - 1, R);
        if(ans != -1)   ans++;
		cout << ans << ' ';
        // queries.push_back(ans);
    }
    // return queries;
}


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> A = {1, 1, 1, 1};
	vector<vector<int>> B = {
		{1, 5},
		{2, 3},
		{4, 4}
	};
	solve(A, B);
}