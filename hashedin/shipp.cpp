#include <bits/stdc++.h>
using namespace std;

pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct GridGraph 
{
    vector<string> A;
    vector<vector<bool>> vis;
    int N, M;
    GridGraph(vector<string>& s) 
    {
        N = s.size();
        M = s[0].length();
        A.swap(s);
        vis.resize(N, vector<bool>(M));
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

vector<int> solution(vector<string>& s)
{
    GridGraph g(s);
    vector<int> ans(3);
    for(int i = 0; i < g.N; i++)
    for(int j = 0; j < g.M; j++)
    if(!g.vis[i][j])
        ans[g.DFS(i, j) - 1]++;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> s = {".##.#", "#.#..", "#...#", "#.##."};
    // vector<string> s = {".#..#", "##..#", "...#."};
    for(auto x: s)  cerr << x << '\n';
    // n = 3, m = 5;
    // dfs(1, 1, s);
    for(auto x: solution(s))
        cout << x << ' ';
}