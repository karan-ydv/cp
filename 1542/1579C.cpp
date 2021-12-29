#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool invalid[n][m]{};
    string s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++)
            if(s[i][j] == '*') invalid[i][j] = 1;
    }
    
    for(int i = n - 1; i >= 0; i--)
    for(int j = 0; j < m; j++) if(s[i][j] == '*')
    {
        int d = 0;
        for(; d <= i and d <= j and j + d < m and s[i - d][j - d] == '*' and s[i - d][j + d] == '*'; d++);
        if(d > k) while(d--)
        {
            invalid[i - d][j - d] = 0;
            invalid[i - d][j + d] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    if(invalid[i][j])
        return false;
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
}