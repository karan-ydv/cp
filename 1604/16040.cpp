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
        int a[n]; for(int &x: a)    cin >> x;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, a[i] - i - 1);
        }
        cout << ans << '\n';
    }
}