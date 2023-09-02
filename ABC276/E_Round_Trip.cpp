#include <bits/stdc++.h>
#define int int64_t
using namespace std;

pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct GridGraph 
{
    vector<string> A;
    vector<vector<bool>> vis;
    int N, M;
    int si, sj;
    GridGraph(int n, int m) : A(n), vis(n, vector<bool>(m, false)), N(n), M(m)
    {
        for(int i = 0; i < n; i++) {
            cin >> A[i];
            int f = find(A[i].begin(), A[i].end(), 'S') - A[i].begin();
            if (f != m) tie(si, sj) = {i, f};
        }
    }
    bool valid(int x, int y){
        return x >= 0 and x < N and y < M and y >= 0;
    }
    int DFS(int a, int b, int c)
    {
        vis[a][b] = true;
        for (auto [dx, dy]: d4)
        {
            int x = a + dx, y = b + dy;
            if (!valid(x, y)) continue;
            if (A[x][y] == 'S' and c > 2)       return c + 1;
            if (vis[x][y] || A[x][y] == '#')    continue;
            int ans = DFS(x, y, c + 1);
            if (ans != -1) return ans + 1;
        }
        return -1;
    }
    void solve()
    {
        if (DFS(si, sj, 1) == -1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    GridGraph G(n, m);
    G.solve();
}
