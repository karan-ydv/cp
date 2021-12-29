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
        int a, b, n, s;
        cin >> a >> b >> n >> s;
        int d = min(s / n, a);
        s -= n * d;
        if(s > b)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}