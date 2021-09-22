#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[30] = {};
        for(int i = 0; i < n; i++)
        {
            int x;  cin >> x;
            for(int b = 1, j = 0; b <= x; j++, b <<= 1)
                a[j] += (x / b) & 1;
        }
        int ans = 0;
        for(int b = 1, j = 0; j < 30; j++, b <<= 1)
            (ans += b * (a[j] * (a[j] - 1) / 2 % mod) % mod) %= mod;
        cout << ans << '\n';
    }
}