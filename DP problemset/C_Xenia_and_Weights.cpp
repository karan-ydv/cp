#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
map<int, bool> dp[N][11];
map<int, int> par[N][11];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;  string s;
    cin >> s >> m;
    s = "0" + s;
    
    for(int i = 1; i <= 10; i++)
        if(s[i] == '1') dp[1][i][i] = 1;

    for(int i = 1; i < m; i++)
    for(int j = 1; j <= 10; j++)
    for(auto [k, y]: dp[i][j]) if(y)
    for(int a = 1; a <= 10; a++)
    if(a != j and s[a] == '1')
    {
        if(i & 1)
        {
            if(k - a < 0)
            {
                dp[i + 1][a][k - a] = 1;
                par[i + 1][a][k - a] = j;
            }
        }
        else
        {
            if(k + a > 0)
            {
                dp[i + 1][a][k + a] = 1;
                par[i + 1][a][k + a] = j;
            }
        }
    }
    bool flag = false;
    int x, y;
    for(int i = 1; i <= 10; i++)
        for(auto [b, f]: dp[m][i])
        {
            flag = true;
            x = i, y = b;
            break;
        }
        
    if(flag)
    {
        cout << "YES\n";
        stack<int> ans;
        for(int i = m; i > 0; i--)
        {
            ans.push(x);
            int z = par[i][x][y];
            if(i & 1) y -= x;
            else      y += x;
            x = z;
        }
        while(!ans.empty())
        {
            cout << ans.top() << ' ';
            ans.pop();
        }
    }
    else        cout << "NO\n";
}