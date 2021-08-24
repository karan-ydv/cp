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
        int ans = 0;
        for(int i = 1; i <= n; i++)
        for(int j = i + i; j <= n; j += i)
            ans += (n - i) / j + 1;
        cout << ans << '\n';
    }
}