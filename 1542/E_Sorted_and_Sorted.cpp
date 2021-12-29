#include <bits/stdc++.h>
using namespace std;

const int N = 2021;
int dp[N][N], val[N + N];
int suff[N + N][N][2], W[N], B[N];
bool col[N + N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for(int i = 1; i <= n + n; i++)
    {
        string s;
        cin >> s >> val[i];
        if(s == "B") {
            col[i] = 1;
            B[val[i]] = i;
        }
        else
            W[val[i]] = i;
    }
    for(int i = n + n; i > 0; i--)
    {
        for(int j = 1; j <= n; j++) {
            suff[i][j][0] = suff[i + 1][j][0];
            suff[i][j][1] = suff[i + 1][j][1];
        }
        for(int j = val[i]; j <= n; j++)
            suff[i][j][col[i]]++;
    }

    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
        dp[i][j] = 1e8;

    dp[0][0] = 0;
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
    {
        int &x = dp[i + 1][j];
        x = min(x, dp[i][j] + suff[W[i + 1]][i][0] + suff[W[i + 1]][j][1]);
        int &y = dp[i][j + 1];
        y = min(y, dp[i][j] + suff[B[j + 1]][i][0] + suff[B[j + 1]][j][1]);
    }

    cout << dp[n][n];
}