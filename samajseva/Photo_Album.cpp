#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("album.in", "r", stdin);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        if(k == 1)
        {
            if(n == 1)
                cout << "1\n";
            else
                cout << "-1\n";
            continue;
        }
        int m = (n + k - 1) / k;
        int ans = m;
        while(m >= k)
        {
            ans += m / k;
            m = m / k + m % k;
        }
        if(m > 1)
            ans++;
        cout << ans << '\n';
    }
}