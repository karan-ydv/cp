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
        int n;
        cin >> n;
        int a[n];
        for(int &x: a)
            cin >> x;
        int x = a[n - 1], ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] > x)
            {
                x = a[i];
                ans++;
            }
        }
        cout << ans << '\n';
    }
}