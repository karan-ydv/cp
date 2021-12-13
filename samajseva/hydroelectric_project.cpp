#include <bits/stdc++.h>
using namespace std;

pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct GridGraph 
{
    vector<string> A;
    vector<vector<bool>> vis;
    vector<vector<int>> cost, tin, low;
    int N, M, ans, timer;
    GridGraph(int n, int m) 
    {
        N = n, M = m;
        A.resize(n);
        cost.resize(n, vector<int>(m));
        tin.resize(n, vector<int>(m));
        low.resize(n, vector<int>(m));
        vis.resize(n, vector<bool>(m));
        for(int i = 0; i < n; i++)
            cin >> A[i];
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> cost[i][j];
        
        ans = int(2e9);
        timer = 0;
    }
    bool valid(int x, int y){
        return x >= 0 and x < N and y < M and y >= 0;
    }
    bool DFS(int x, int y, int p)
    {
        vis[x][y] = 1;
        tin[x][y] = low[x][y] = timer++;

        bool f = (x == N - 1 and y == M - 1);
        for(auto [dx, dy]: d4)
        {
            int x1 = x + dx;
            int y1 = y + dy;

            if(valid(x1, y1) == false)  continue;
            if(A[x1][y1] == '#')        continue;
            if(x1 * M + y1 == p)        continue;

            if(vis[x1][y1])
                low[x][y] = min(low[x][y], tin[x1][y1]);
            else
            {
                bool flag = DFS(x1, y1, x * M + y);
                low[x][y] = min(low[x][y], low[x1][y1]);
                if(low[x1][y1] >= tin[x][y])
                {
                    if(flag == true)
                    ans = min(ans, cost[x][y]);
                }
                f |= flag;
            }
        }
        return f;
    }
    void solve()
    {
        if(A[0][0] == '#')  ans = 0;
        else                ans = min(ans, cost[0][0]);

        if(A[N - 1][M - 1] == '#')  ans = 0;
        else                        ans = min(ans, cost[N - 1][M - 1]);

        DFS(0, 0, -1);

        cout << ans << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    GridGraph g(n, m);
    g.solve();
}