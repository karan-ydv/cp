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
        int n, k;   cin >> n >> k;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x, y;   cin >> x >> y;
            if(k >= x and k <= y)
            ans = max(ans, y - k + 1);
        }
        cout << ans << '\n';
    }
}