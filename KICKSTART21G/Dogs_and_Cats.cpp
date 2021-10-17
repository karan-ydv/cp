#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve()
{
    string s;
    int n, d, c, m; cin >> n >> d >> c >> m >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'D')
        {
            if(d == 0)  return false;
            d--;
            c += m;
        }
        else
        {
            if(c == 0)
                return s.find('D', i) == string::npos;
            c--;
        }
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
}