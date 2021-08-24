#include <bits/stdc++.h>
using namespace std;

pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> d8[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
struct GridGraph 
{
    vector<string> G;
    vector<vector<bool>> vis;
    int N, M;
    GridGraph(int n, int m) : N(n), M(m)
    {
        G.resize(n);
        for(int i = 0; i < n; i++)
            cin >> G[i];
    }
    bool valid(int x, int y){
        return x >= 0 and x < N and y < M and y >= 0;
    }
    int fun(int a, int b)
    {
        // cerr << "h" << endl;
        vector<pair<int, int>> v;
        unordered_map<int, unordered_map<int, int>> mp;
        function<void(int, int)> dfs = [&](int x, int y)
        {
            vis[x][y] = 1;
            v.emplace_back(x, y);
            for(auto [dx, dy]: d4) {
                int x1 = x + dx, y1 = y + dy;
                if(valid(x1, y1) and !vis[x1][y1])
                if(G[x1][y1] != '.') dfs(x1, y1);
            }
        };
        function<void(int, int)> dfs2 = [&](int x, int y)
        {
            mp[x][y] = 1;
            for(auto [dx, dy]: d4) {
                int x1 = x + dx, y1 = y + dy;
                if(valid(x1, y1) and !mp[x1][y1])
                if(G[x1][y1] == 'X') dfs2(x1, y1);
            }
        };
        dfs(a, b);
        int ans = 0;
        for(auto [c, d]: v)
        if(G[c][d] == 'X' and !mp[c][d])
            ans++, dfs2(c, d);
        return ans;
    }
    void solve()
    {
        vector<int> dots;
        vis.resize(N, vector<bool>(M));
        for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        if(G[i][j] != '.' and !vis[i][j])
            dots.emplace_back(fun(i, j));
        sort(dots.begin(), dots.end());
        for(int i = 0; i + 1 < dots.size(); i++)
            cout << dots[i] << ' ';
        if(dots.size())
        cout << dots.back();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w, h, t = 0;
    cin >> w >> h;
    while(++t)
    {
        cout << "Throw " << t << '\n';
        GridGraph g(h, w);
        g.solve();
        cin >> w >> h;
        if(w == 0 and h == 0)
            break;
        cout << "\n\n";
    }
}