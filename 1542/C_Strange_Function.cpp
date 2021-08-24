#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
inline int lcm(int a, int b) { return a * b / __gcd(a, b); }
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int ans = 0, m = n, x = 1;
        for(int i = 2; x <= n; i++)
        {
            int l = lcm(x, i);
            int k = (n / x) - (n / l); // numbers that are not divisible by i but are multiples of x
            (ans += i * k) %= mod;
            x = l;
        }
        cout << ans << '\n';
    }
}