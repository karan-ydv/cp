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
        int n, p, k;    cin >> n >> p >> k;
        int i = p % k;
        int m = n / k;
        int ans = i * m + p / k + 1;
        ans += min(n % k, i);
        cout << ans << '\n';
    }
}