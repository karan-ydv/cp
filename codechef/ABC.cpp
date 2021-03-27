#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio;
    cin.tie(0);
    int n;  cin >> n;
    vector<pair<int, bool>> graph[n];
    for(int i = 1; i < n; i++) {
        int u, v, w;    cin >> u >> v >> w;
        u--, v--, w--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    function<int(int, int p, bool)> dfs = [&](int u, int p, bool untidy) {
        int c = 0;
        if(graph[u].size() == 0)
            c += untidy;
        for(auto [v, f]: graph[u]) {
            if(v != p)
            c += dfs(v, p, untidy & f);
        }
        return c;
    };
    int ans = dfs(0, -1, true);
    cout << ans;
}