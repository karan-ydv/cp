#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solve(int n)
{
    int ans = n;
    for(int i = 2, f = 0; i <= n; i <<= 1)
    {
        if (f)
        {
            ans += n / i;
            f = 0;
        }
        else
        {
            ans -= n / i;
            f = 1;
        }
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}