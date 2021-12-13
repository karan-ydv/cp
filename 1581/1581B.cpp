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
        int n, m, k;
        cin >> n >> m >> k;
        k -= 2;
        if(m < n - 1 or k < 0 or m > n * (n - 1) / 2) {
            cout << "NO\n";
            continue;
        }
        if(k == 0)
            n == 1 ? cout << "YES\n" : cout << "NO\n";
        else if(k == 1)
            m == n * (n - 1) / 2 ? cout << "YES\n" : cout << "NO\n";
        else cout << "YES\n";
    }
}