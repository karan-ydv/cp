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
        int n, k;	cin >> n >> k;
        int ans = (n - k + (k - 1) / 2) * 2;
        cout << ans << '\n';
    }
}