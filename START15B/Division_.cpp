#include <bits/stdc++.h>
#define int int64_t
using namespace std;

pair<int, int> fun(int n)
{
    int x = 0, y = 0;
    while(n % 2 == 0) {
        n /= 2; x++;
    }
    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            n /= i; y++;
        }
    }
    if(n > 1) y++;
    return {x, y};
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        auto [x, y] = fun(n);
        int ans;
        if(a < 0 and b < 0)
            ans = n & 1 ? b : a;
        else if(a < 0 and b >= 0)
            ans = min(int(1), x) * a + b * y;
        else if(a >= 0 and b < 0)
        {
            ans = x * a;
            if(x == 0)
                ans += b;
        }
        else
            ans = a * x + b * y;

        cout << ans << '\n';
    }
}