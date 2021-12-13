#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 43;
bool dp[N][N][N][N];
int pre[N][N][N][N];

// dp[i][r][a][b] = 1 if its possible to have 

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s; int n, a, b;
        cin >> n >> a >> b >> s;
        s = "!" + s;
        for(int i = 1; i <= n; i++) {

        }

        int ans = 1e9;
        for(int i = 1; i < n; i++) {
            if(dp[n][i][0][0])  ans = min(ans, n - 2 * i);
        }
        if(ans == 1e9)
            cout << "-1\n";
        else
        {
            
        }
    }
}