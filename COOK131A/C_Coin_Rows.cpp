#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+69;
int a[2][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        for(int i: {0, 1})
        for(int j = 0; j < n; j++)
            cin >> a[i][j];        
        int sum1 = accumulate(a[0], a[0] + n, 0);
        int ans = 2e9, sum2 = 0;
        for(int i = 0; i < n; i++)
        {
            sum1 -= a[0][i];
            ans = min(ans, max(sum1, sum2));
            sum2 += a[1][i];
        }
        cout << ans << '\n';
    }
}