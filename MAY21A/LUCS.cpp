#include <bits/stdc++.h>
using namespace std;

int shortestUnSubUP(string S, string T)
{
    const int MAX = 1e3;
    int n = S.length(), m = T.length();
    S = "!" + S;
    T = "!" + T;
    int dp[n + 1][m + 1];
    dp[n][m] = 1 << 20;
    int prev[26][m + 1];
    for(char c = 'a'; c <= 'z'; c++)
    {
        prev[c - 'a'][0] = 0;
        for(int i = 1; i <= n; i++)
            prev[c - 'a'][i] = (T[i] == c) ? i : prev[c - 'a'][i - 1];
    }
    for(int i = 1; i <= n; i++)  dp[i][0] = 1;
    for(int i = 0; i <= m; i++)  dp[0][i] = MAX;

    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
    {
        int k = prev[S[i] - 'a'][j];
        if(k == 0)
            dp[i][j] = 1;
        else
            dp[i][j] = min(1 + dp[i - 1][k - 1], dp[i - 1][j]);
    }
    if(dp[n][m] >= MAX)
        dp[n][m] = -1;
    return dp[n][m];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    cout << shortestUnSubUP(s1, s2);
}