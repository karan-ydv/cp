#include <bits/stdc++.h>
using namespace std;

#define rof(i, a, b) for(int i = a; i <= b; i++)

const int N = 2005;
int dp[N][N];
bool vis[N][N];
bool cyc[N][N];
string s[N];

map<char, pair<int, int>> mp
{
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}}
};

int ans, xx, yy;
int dfs(int x, int y)
{
    if(vis[x][y])
    {
        if(dp[x][y] == -1)
            return cyc[x][y] = 1, 0;
        return dp[x][y];
    }
    vis[x][y] = 1;
    auto [dx, dy] = mp[s[x][y]];
    int a = x + dx, b = y + dy;
    dp[x][y] = 1 + dfs(a, b);
    if(ans < dp[x][y])
    {
        ans = dp[x][y];
        xx = x;
        yy = y;
    }
    return dp[x][y];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < N; i++)
        vis[i][0] = vis[0][i] = 1;
    
    int t;	cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        rof(i, 1, n)    cin >> s[i], s[i] = "!" + s[i];
        
        rof(i, 1, n) rof(j, 1, m)    dp[i][j] = -1, vis[i][j] = cyc[i][j] = 0;

        rof(i, 1, n + 1)    dp[i][m + 1] = 0, vis[i][m + 1] = 1;
        rof(j, 1, m + 1)    dp[n + 1][j] = 0, vis[n + 1][j] = 1;

        ans = 0, xx = 1, yy = 1;

        rof(i, 1, n) rof(j, 1, m)   if(!vis[i][j])  dfs(i, j);
        rof(i, 1, n) rof(j, 1, m)   vis[i][j] = false;
        rof(i, 1, n) rof(j, 1, m)
        if(cyc[i][j] and !vis[i][j])
        {
            vis[i][j] = 1;
            auto [dx, dy] = mp[s[i][j]];
            int x = i + dx, y = j + dy;
            while((x != i or y != j) and !vis[x][y])
            {
                vis[x][y] = 1;
                cyc[x][y] = 1;
                dp[x][y] = dp[i][j];
                tie(dx, dy) = mp[s[x][y]];
                x += dx, y += dy;
            }
        }
        rof(i, 1, n) rof(j, 1, m)   if(!vis[i][j])  dfs(i, j);
        cout << xx << ' ' << yy << ' ' << ans << '\n';
    }
}