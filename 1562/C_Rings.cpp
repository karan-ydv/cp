#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve()
{
    int n;	cin >> n;
    string s;   cin >> s;
    s = "!" + s;
    if(s.find('0') != string::npos)
    {
        int i = s.find('0');
        if(i - 1 >= n / 2)
        {
            cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << '\n';
        }
        else
        {
            cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
        }
    }
    else
    {
        cout << 1 << ' ' << n / 2 << ' ' << 2 << ' ' << n / 2 + 1 << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve();
    }
}