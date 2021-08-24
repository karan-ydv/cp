#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;
        int ans = Xa / xa + Xb / xb;
        cout << ans << '\n';
    }
}