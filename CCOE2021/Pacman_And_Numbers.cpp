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
        int a[n][n];
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
        int ans = 0;
        for(int i = 0; i <= n - i - 1; i += 2)
        {
            for(int j = i; j <= n - i - 1; j++)
                ans += a[i][j];
            
            for(int k = i + 1; k < n - i - 1; k++)
                ans += a[k][i];

            if(i != n - i - 1)
            {
                for(int j = i; j <= n - i - 1; j++)
                    ans += a[n - i - 1][j];

                for(int k = i + 1; k < n - i - 1; k++)
                    ans += a[k][n - i - 1];
            }
        }
        cout << ans << '\n';
    }
}