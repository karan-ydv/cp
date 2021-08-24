#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int p[N][26];
int par[N], dp[N];
char c[N];

// dp[i] = length of smallest uncommon subsequnce of last n characters string
// important! dp[0] = 1

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;   cin >> s;
    int n = s.length();
    s = s + "!";
    reverse(s.begin(), s.end());

    fill_n(dp, n + 1, 1e9);
    dp[0] = 1; c[0] = 'a'; par[0] = -1;

    for(int i = 1; i <= n; i++)
    for(int j = 0; j < 26; j++)
    {
        int &prev = p[i][j];
        prev = s[i] == ('a' + j) ? i : p[i - 1][j];

        if(prev == 0)
        {
            if(dp[i] > 1)
            {
                dp[i] = 1;
                par[i] = -1;
                c[i] = 'a' + j;
            }
        }
        else if(dp[prev - 1] + 1 < dp[i])
        {
            par[i] = prev - 1;
            c[i] = 'a' + j;
            dp[i] = dp[prev - 1] + 1;
        }
    }
    
    string ans = "";
    for(int i = n; i >= 0; i = par[i])
        ans += c[i];
    cout << ans;
}