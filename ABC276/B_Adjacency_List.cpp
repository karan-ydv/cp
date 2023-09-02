#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<set<int>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int i = 1; i <= n; i++)
  {
    cout << adj[i].size() << " ";
    for (auto x : adj[i])
      cout << x << " ";
    cout << '\n';
  }
}
