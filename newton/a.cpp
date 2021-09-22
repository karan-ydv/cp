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
        int x, y, z;    cin >> x >> y >> z;
        cout << max(z - x, z - y) << '\n';
    }
}