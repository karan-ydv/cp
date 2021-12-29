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
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        b -= a;
        int ans = min(a, b / 2);
        ans += (a - ans) / 2;
        cout << ans << '\n';
    }
}