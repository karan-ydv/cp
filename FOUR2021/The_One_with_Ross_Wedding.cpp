#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve()
{
    int n, p, q; string s;
    cin >> n >> p >> q >> s;
    p = abs(p);
    q = abs(q);
    int zero = count(s.begin(), s.end(), '1');
    int ones = n - zero;
    if(zero >= p and ones >= q)
    {
        if(zero % 2 == p % 2  and ones % 2 == q % 2)
            return true;
    }
    if(zero >= q and ones >= p)
    {
        if(zero % 2 == q % 2  and ones % 2 == p % 2)
            return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
}