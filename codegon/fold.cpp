#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve()
{
    int n, m;   cin >> n >> m;
    int c, d;   cin >> c >> d;
    int a[n][m];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin >> a[n][m];
    
    if(n == 1 and m == 1)
        return cout << "error\n", void();
    if((c & 1) == (d & 1))
    {
        if(n != m)  return cout << "error\n", void();
        if(c == 1 or c == 3)
        {
            cerr
            for(int i = 0; i < n; i++)
            for(int j = 0; j < n - i; j++)
            if(a[i][j] != a[n - 1 - j][n - i - 1])
                return cout << "error\n", void();
            for(int i = 0; i < n; i++)
            {
                int k = (c == 1 ? n - i - 1 : n - i);
                for(int j = 0; j < k; j++)  cout << (c == 1 ? '-' : a[i][j]);
                for(int j = k; j < m; j++)  cout << (c == 3 ? '-' : a[i][j]);
                cout << '\n';
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            for(int j = i; j < m; j++)
            if(a[i][j] != a[j][i])
                return cout << "error\n", void();
            for(int i = 0; i < n; i++)
            {
                int k = (c == 4 ? i : i + 1);
                for(int j = 0; j < k; j++)  cout << (c == 4 ? '-' : a[i][j]);
                for(int j = k; j < m; j++)  cout << (c == 2 ? '-' : a[i][j]);
                cout << '\n';
            }
        }
    }
    else
    {
        if((c == 1 and d == 2) or (c == 4 and d == 3))
        {
            for(int i = 0; i < n; i++)
            for(int j = 0; j < m / 2; j++)
            if(a[i][j] != a[i][m - 1 - j])
                return cout << "error\n", void();

            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cout << (j < m / 2 ? '-' : a[i][j]);            
        }
        else if((d == 1 and c == 2) or (d == 4 and c == 3))
        {
            for(int i = 0; i < n; i++)
            for(int j = 0; j < m / 2; j++)
            if(a[i][j] != a[i][m - 1 - j])
                return cout << "error\n", void();

            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cout << (j >= m / 2 ? '-' : a[i][j]);            
        }
        else if((c == 1 and d == 4) or (c == 2 and d == 3))
        {
            for(int i = 0; i < n / 2; i++)
            for(int j = 0; j < m; j++)
            if(a[i][j] != a[n - i - 1][j])
                return cout << "error\n", void();

            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cout << (i < n / 2 ? '-' : a[i][j]);            
        }
        else
        {
            for(int i = 0; i < n / 2; i++)
            for(int j = 0; j < m; j++)
            if(a[i][j] != a[n - i - 1][j])
                return cout << "error\n", void();

            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cout << (i >= n / 2 ? '-' : a[i][j]);            
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++)
    {
        cout << _ << '\n';
        solve();
    }
}