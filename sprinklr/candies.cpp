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
        int n, k; cin >> n >> k;
        int a[n], b[n - 1];
        for(int &x: a)  cin >> x;
        for(int i = 0; i + 1 < n; i++)
            b[i] = a[i] + a[i + 1];
        sort(b, b + n - 1);
        int ans = 0;
        for(int i = 0; i + 1 < k; i++)
            ans += b[n - 2 - i] - b[i];
        cout << ans << '\n';
    }
}