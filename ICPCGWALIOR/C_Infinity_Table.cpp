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
        int n, k;	cin >> k;
        int s = sqrt(k);
        if(s * s == k)
            cout << s << " 1\n";
        else
        {
            k -= s * s;
            if(k <= s)
                cout << k << ' ' << s + 1 << '\n';
            else k -= s,
                cout << s + 1 << ' ' << s + 2 - k << '\n';
        }
    }
}