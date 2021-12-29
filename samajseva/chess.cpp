#include <bits/stdc++.h>
using namespace std;

int n;

bool valid(int x, int y) {
    return x > 0 and x <= n and y <= n and y > 0;
}

pair<int, int> moves[] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

int bfs(int x, int y, int a, int b)
{
    vector<vector<bool>> vis(n + 5, vector<bool>(n + 5));
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    while(!q.empty())
    {
        int u = get<0>(q.front());
        int v = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();
        if(u == a and v == b)
            return d;
        vis[u][v] = 1;
        for(int i = 0; i < 8; i++)
        {
            int dx = moves[i].first;
            int dy = moves[i].second;
            if(valid(u + dx, v + dy) and !vis[u + dx][v + dy]) {
                q.push({u + dx, v + dy, d + 1});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1, x2, y2);
}