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
        int ans = 0;
        while(n)
        {
            ans++;
            if(ans % 3 == 0 or ans % 10 == 3);
            else
                n--;
        }
        cout << ans << '\n';
    }
}