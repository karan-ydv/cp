#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve()
{
    string s; int n;
    cin >> n >> s;
    bool f[4] = {1};
    int d = 0;
    for(char c: s)
    {
        if(c == 'R')    (d += 1) %= 4;
        else            (d += 3) %= 4;
        if(f[(d + 2) % 4])  return true;
        f[d] = 1;
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
        if(solve()) cout << "YES\n";
        else        cout << "NO\n";
    }
}