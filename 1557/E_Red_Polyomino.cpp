#include <bits/stdc++.h>
using namespace std;

string s[8];
int n, ans = 0;
pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int x, int y) {
    return x >= 0 and x < n and y < n and y >= 0 and s[x][y] == '@';
}

void dfs(int k)
{
    if(k == 0)
        return ans++, void();
    
    vector<pair<int, int>> next;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)  if(s[i][j] == '.')
    for(auto [dx, dy]: d4)      if(valid(i + dx, j + dy))
    {
        next.emplace_back(i, j);
        s[i][j] = '@';
        dfs(k - 1);
        s[i][j] = '#';
        break;
    }

    for(auto [x, y]: next)
        s[x][y] = '.';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;  cin >> n >> k;
    for(int i = 0; i < n; i++)  cin >> s[i];

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    if(s[i][j] == '.')
    {
        s[i][j] = '@';
        dfs(k - 1);
        s[i][j] = '#';
    }
    cout << ans;
}