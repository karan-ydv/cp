#include <bits/stdc++.h>
using namespace std;

bool visited[101][101];
int n, m;

bool valid(int x, int y)
{
    
    cerr << x << ' ' << y << " : " << (0 <= x and x < n and 0 <= y and y < m) << '\n';
    return x >= 0 and x < n and y >= 0 and y < m;
}

pair<int, int> D[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dfs(int x, int y, vector<string>& s)
{
    cerr << x << ' ' << y << ":\n";
    visited[x][y] = 1;
    int c = 1;
    for(int i = 0; i < 4; i++)
    {
        int dx = D[i].first;
        int dy = D[i].second;
        int u = x + dx, v = y + dy;
        if(valid(u, v) and !visited[u][v] and s[u][v] == '#')
            c += dfs(u, v, s);
    }
    cerr << c << '\n';
    return c;
}

vector<int> solution(vector<string>& s)
{
    n = s.size(), m = s[0].length();
    cerr << "n = "<< n << " m = " << m << '\n';
    vector<int> ans(3);

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        visited[i][j] = false;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    if(s[i][j] == '#' and !visited[i][j])
        ans[dfs(i, j, s) - 1]++;

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // vector<string> s = {".##.#", "#.#..", "#...#", "#.##."};
    vector<string> s = {".#..#", "##..#", "...#."};
    for(auto x: s)  cerr << x << '\n';
    // n = 3, m = 5;
    // dfs(1, 1, s);
    for(auto x: solution(s))
        cout << x << ' ';
}