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
        int ans = 0, l = 0;
        for(int i = 2; i < n; i++) {
            if(a[i] > a[i - 1] and a[i - 1] > a[i - 2])
            {
                cerr << i << '\n';
                ans += (i - l) * (i - l + 1) / 2;
                l = i - 1;
            }
            else if(a[i] < a[i - 1] and a[i - 1] < a[i - 2])
            {
                ans += (i - l) * (i - l + 1) / 2;
                l = i - 1;
            }
        }
        ans += (n - l) * (n - l + 1) / 2;
        cout << ans << '\n';
    }
}