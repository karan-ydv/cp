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
        int b = 1, ans = 0;
        while(b < n)
        {
            b <<= 1;
            ans++;
            if(b >= k)
            {
                ans += (max(n - b, 0ll) + k - 1) / k;
                break;
            }
        }
        cout << ans << '\n';
    }
}