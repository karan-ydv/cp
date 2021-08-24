#include <bits/stdc++.h>
using namespace std;

typedef bitset<300> edge;
int A[20][20], n, q;
pair<int, int> C[10];
bool valid(int x)   { return (x < n and x >= 0); }
tuple<int, edge, edge> cost(int set, int j, edge h, edge v)
{
    int dst[n][n];
    bool vis[n][n];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        dst[i][j] = 1 << 30, vis[i][j] = false;
    int cst = 0;

    return {cst, h, v};
};


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
        
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            int x, y;   cin >> x >> y;
            C[i] = {x, y};
        }
        pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto cost = [&](int set, int j, edge h, edge v)
        {
            if(set == 0)
                return 0;
            
        };
        int m = 1 << q;
        edge horz[m];
        edge vert[m];
        vector<int> dp(m, 1 << 30);
        dp[0] = 0;
        for(int i = 0; i < m - 1; i++)
        {
            for(int j = 0, b = 1; j < q; j++, b <<= 1)
            if(!(i & b))
            {
                auto [cst, h, v] = cost(i, j, horz[i], vert[i]);
                if(cst < dp[i | b])
                {
                    dp[i | b] = cst;
                    horz[i | b] = h;
                    vert[i | b] = v;
                }
            }
        }
        int ans = 0;
        for(int x: dp)  ans += x;
        cout << x;
    }
}