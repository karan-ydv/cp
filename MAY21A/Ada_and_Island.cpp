#include <bits/stdc++.h>
#define int int64_t
using namespace std;

pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> d8[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
struct GridGraph 
{
    vector<string> A;
    vector<vector<bool>> vis;
    int N, M;
    GridGraph(int n, int m) 
    {
        N = n, M = m;
        A.resize(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
    }
    bool valid(int x, int y){
        return x >= 0 and x < N and y < M and y >= 0;
    }
    int DFS(int x, int y)
    {
        vis[x][y] = 1;
        if(A[x][y] == '~')  return 0;
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
    void solve()
    {
        int sum = 0, cnt = 0;
        vis.resize(N, vector<bool>(M));
        for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        if(A[i][j] == '#' and !vis[i][j])
        {
            int x = DFS(i, j);
            sum += x * x;
        }
        if(sum == 0)    return cout << "0\n", void();
        int q = N * M;
        int g = __gcd(sum, q);
        sum /= g;
        q /= g;
        cout << sum;
        if(q != 1)  cout << " / " << q;
        cout << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        GridGraph g(n, m);
        g.solve();
    }
}