#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n;  cin >> n;
    if(n < 4)   return n;
    return (n + 1) / 2 + n / 4;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
}