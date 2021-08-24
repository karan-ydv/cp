#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        if(n == 2)
        {
            cout << "-1\n";
            continue;
        }
        int a[n][n];

        int c = 0;
        for(int i = 0; i < n; i++)
            a[i][i] = ++c;
        for(int i = 1; i < n; i++)
        {
            int x = 0, y = i;
            for(; x < n and y < n; x += 1, y += 1)
                a[x][y] = ++c;
            x = i, y = 0;
            for(; x < n and y < n; x += 1, y += 1)
                a[x][y] = ++c;
        }
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " \n"[j == n - 1];
    }
}