#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf = 1e18;
const int N = 3001;
int dp[N][N];

struct Graph {
    typedef pair<int, int> item;
    vector<tuple<int, int, int>> edges;
    vector<int> dist, cnt;
    int V, E;
    Graph(int v, int e) : V(v), E(e)
    {
        edges.reserve(e);
        for(int i = 0; i < e; i++)
        {
            int u, v, w;	cin >> u >> v >> w;
            if(u == v)  continue;
            edges.emplace_back(u, v, w);
            edges.emplace_back(v, u, w);
        }
    }
	void solve()
	{
        fill_n(dp[0], N * N, inf);

        dp[1][0] = 0;
        
        for(int i = 1; i < V; i++)
        for(auto [u, v, w]: edges)
        {
            dp[v][i] = min(dp[v][i], dp[u][i - 1] + i * w);
        }

		for(int i = 1; i <= V; i++)
        {
            int d = dp[i][0];
            for(int j = 1; j <= V; j++)
                d = min(d, dp[i][j]);
            if(d >= inf)
                cout << "-1\n";
            else
    			cout << d << '\n';
        }
	}
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    Graph g(n, m);
    g.solve();
}   