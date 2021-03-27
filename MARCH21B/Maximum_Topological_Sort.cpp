#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
const int mod =  1e9+7;
int fact[N], factinv[N];
double factlog[N];

int modexp(int a, int n) {
	int x = 1;
	while(n)
	{
		if(n & 1)	x = x * a % mod;
		n >>= 1;
		a = a * a % mod;
	}
	return x;
}

void preprocess() {
	fact[0] = 1;
	for(int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i % mod;
		factinv[i] = modexp(fact[i], mod - 2);
		factlog[i] = factlog[i - 1] + log(i);
	}
}

void mul(int &x, int v) {
	x *= v;
	if(x >= mod)
		x %= mod;
}
struct Graph {
	typedef int item;
	typedef vector<vector<item>> vv;
	vector<int> ord, siz;
	vector<double> max;
	vv adj;
	int n;
	Graph(int v, int e) {
		n = v;
		adj.resize(v);
		ord.resize(v);
		siz.resize(v);
		max.resize(v);
		while(e--)
		{
			int u, v;	cin >> u >> v;
			u--, v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}
	void DFS(int u = 0, int p = -1)
	{
		ord[u] = siz[u] = 1;
		for(auto v: adj[u])
		if(v != p)
		{
			DFS(v, u);
			siz[u] += siz[v];
			max[u] += max[v];
			max[u] -= factlog[siz[v]];
			mul(ord[u], ord[v]);
			mul(ord[u], factinv[siz[v]]);
		}
		mul(ord[u], fact[siz[u] - 1]);
		max[u] += factlog[siz[u] - 1];
	}
	void DFS2(int u = 0, int p = -1)
	{
		for(auto v: adj[u])
		if(v != p)
		{
			ord[v] = ord[u];
			mul(ord[v], siz[v]);
			mul(ord[v], modexp(n - siz[v], mod - 2));
			max[v] = max[u] + factlog[siz[v]] - factlog[siz[v] - 1];
			max[v] -= factlog[n - siz[v]] - factlog[n - siz[v] - 1];

			DFS2(v, u);
		}
	}
	void solve(int k)
	{
		DFS(); DFS2();
		double mx = 0;
		int u = 0, ORD = -1;
		for(int i = 0; i < n; i++)
		{
			if(ORD == ord[i]) {
				u = i;
			}
			else if(max[i] > mx) {
				mx = max[i];
				ORD = ord[i];
				u = i;
			}
		}
		if(k == 2) {
			ORD = -1;
			int u2 = u; mx = 0;
			for(int i = 0; i < n; i++) if(i != u2)
			{
				if(ORD == ord[i]) {
					u = i;
				}
				else if(max[i] > mx) {
					mx = max[i];
					ORD = ord[i];
					u = i;
				}
			}
		}
		cout << u + 1 << ' ' << ord[u] << '\n';
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	preprocess();
	int t;	cin >> t;
	while(t--)
	{
		int n, k;	cin >> n >> k;
		Graph g(n, n - 1);
		g.solve(k);
	}
}