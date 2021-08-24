#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
int dp[N][26];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  string s;
    cin >> n >> s;

    for(int i = 1; i <= n; i++)
    for(int j = 0; j < 26; j++)
    {
        int r = 0, cnt = 0;
        int &x = dp[i][j];
        // cnt = freq of c != j in [k, r]
        for(int k = 0; k < n; k++)
        {
            for(; r < n; r++) if(s[r] - 'a' != j)
            {
                if(cnt == i)    break;
                cnt++;
            }
            x = max(x, r - k);
            cnt -= (s[k] - 'a' != j);
        }
    }

    int q;  cin >> q;
    while(q--)
    {
        int m; char c;
        cin >> m >> c;
        cout << dp[m][c - 'a'] << '\n';
    }
}