#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e3+7;
int H[N][N], V[N][N];
bool vis[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n, m;   cin >> n >> m;
        string s[n + 1];
        for(int i = 0; i < n; i++)
            cin >> s[i];
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            H[i][j] = V[i][j] = -1;
            vis[i][j] = false;
        }
        
        s[n] = string(m + 1, '#');
        for(int i = 0; i < n; i++)
        {
            s[i] += '#';
            int prev = 0;
            for(int j = 0; j <= m; j++) if(s[i][j] == '#')
            {
                for(int k = prev; k < j; k++)
                    H[i][k] = j - k + prev - 1;
                prev = j + 1;
            }
        }
        for(int j = 0; j < m; j++)
        {
            int prev = 0;
            for(int i = 0; i <= n; i++) if(s[i][j] == '#')
            {
                for(int k = prev; k < i; k++)
                    V[k][j] = i - k + prev - 1;
                prev = i + 1;
            }
        }

        int ans = 0;

        function<void(int, int)> dfs = [&](int i, int j)
        {
            vis[i][j] = true;
            if(H[i][j] != -1 and !vis[i][H[i][j]])
            {
                if(s[i][H[i][j]] == '.')
                {
                    ans++;
                    s[i][H[i][j]] = s[i][j];
                }
                dfs(i, H[i][j]);
            }
            if(V[i][j] != -1 and !vis[V[i][j]][j])
            {
                if(s[V[i][j]][j] == '.')
                {
                    ans++;
                    s[V[i][j]][j] = s[i][j];
                }
                dfs(V[i][j], j);
            }
        };
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(isalpha(s[i][j]) and !vis[i][j])
        {
            dfs(i, j);
        }

        cout << ans << '\n';
        for(int i = 0; i < n; i++) {
            s[i].pop_back();
            cout << s[i] << '\n';
        }
    }
}