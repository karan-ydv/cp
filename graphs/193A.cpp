#include <bits/stdc++.h>
using namespace std;

pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct GridGraph 
{
    vector<string> A;
    vector<vector<bool>> vis;
    int N, M;
    GridGraph(vector<string> &v) 
    {
        N = v.size();
        M = v[0].size();
        A.swap(v);
    }
    bool valid(int x, int y){
        return x >= 0 and x < N and y < M and y >= 0;
    }
    int DFS(int x, int y)
    {
        vis[x][y] = 1;
        if(A[x][y] == '.')  return 0;
        int c = 1;
        for(auto [dx, dy]: d4)
        {
            int x1 = x + dx;
            int y1 = y + dy;
            if(valid(x1, y1) and !vis[x1][y1])
                c += DFS(x1, y1);
        }
        return c;
    }
};

int dfs(int i, int j)
{
    int c = 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    int c = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        c += count(v[i].begin(), v[i].end(), '#');
    }
    GridGraph g(v);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    if(g.A[i][j] == '#')
    if()
        return cout << 
    {
        s[i][j] = '#';
        if(dfs(i, j))
    }

}