#include <bits/stdc++.h>
using namespace std;

const int N = 4e3+5;
int dp[N][N];
int p1[2][N];
int p2[2][N];
char A[N][N];
pair<int, int> par[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int n = s1.length();
    int m = s2.length();

    s1 = "!" + s1; s2 = "!" + s2;
    for(int i = 1; i <= n; i++) for(int c : {0, 1})
        p1[c][i] = s1[i] == ('0' + c) ? i : p1[c][i - 1];
    for(int i = 1; i <= m; i++) for(int c : {0, 1})
        p2[c][i] = s2[i] == ('0' + c) ? i : p2[c][i - 1];

    dp[0][0] = 1;
    A[0][0] = '0';
    par[0][0] = {-1, -1};
    for(int i = 1; i <= n; i++)
    {
        int a = p1[0][i], b = p1[1][i];
        if(a == 0 or b == 0)
        {
            dp[i][0] = 1, par[i][0] = {-1, -1};
            if(a == 0)  A[i][0] = '0';
            else        A[i][0] = '1';
        }
        else
        {
            dp[i][0] = 1 + min(dp[a - 1][0], dp[b - 1][0]);
            if(dp[a - 1][0] <= dp[b - 1][0])
                par[i][0] = {a - 1, 0}, A[i][0] = '0';
            else
                par[i][0] = {b - 1, 0}, A[i][0] = '1';
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int a = p2[0][i], b = p2[1][i];
        if(a == 0 or b == 0)
        {
            dp[0][i] = 1, par[0][i] = {-1, -1};
            if(a == 0)  A[0][i] = '0';
            else        A[0][i] = '1';
        }
        else
        {
            dp[0][i] = 1 + min(dp[0][a - 1], dp[0][b - 1]);
            if(dp[0][a - 1] <= dp[0][b - 1])
                par[0][i] = {0, a - 1}, A[0][i] = '0';
            else
                par[0][i] = {0, b - 1}, A[0][i] = '1';
        }
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        int a = p1[0][i], b = p2[0][j];
        int x = p1[1][i], y = p2[1][j];
        if((a == 0 and b == 0) or (x == 0 and y == 0))
        {
            dp[i][j] = 1;
            par[i][j] = {-1, -1};
            A[i][j] = '1' - (a == 0 and b == 0);
            continue;
        }
        a -= (a != 0), b -= (b != 0);
        x -= (x != 0), y -= (y != 0);
        if(dp[a][b] <= dp[x][y])
        {
            dp[i][j] = 1 + dp[a][b];
            par[i][j] = {a, b};
            A[i][j] = '0';
        }
        else
        {
            dp[i][j] = 1 + dp[x][y];
            par[i][j] = {x, y};
            A[i][j] = '1';
        }
    }
    string s = "" + A[n][m];
    for(int i = n, j = m; i > -1 or j > -1; tie(i, j) = par[i][j])
    {
        s += A[i][j];
    }
    cout << s;
}