#include <bits/stdc++.h>
using namespace std;

queue<array<int, 3>> q;
const int K = 105;
bool vis[K][K][K];
int point[K][K][K];

vector<array<int, 3>> d = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

inline bool valid(int x, int y, int z)
{
    return 0 <= x and x <= 100 and 
           0 <= y and y <= 100 and
           0 <= z and z <= 100;
}

void BFS()
{
    while(!q.empty())
    {
        auto [x, y, z] = q.front();
        q.pop();
        for(auto [dx, dy, dz]: d)
        if(valid(x + dx, y + dy, z + dz))
        {
            int a = x + dx, b = y + dy, c = z + dz;
            if(!vis[a][b][c])
            {
                vis[a][b][c] = 1;
                point[a][b][c] = point[x][y][z];
                q.push({a, b, c});
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;  cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        int x, y, z;    cin >> x >> y >> z;
        point[x][y][z] = i;
        vis[x][y][z] = 1;
        q.push({x, y, z});
    }
    BFS();
    while(t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cout << point[x][y][z] << '\n';
    }
}