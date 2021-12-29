#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1 = "", s2 = "";
    int n, c = 0;    cin >> n >> n;
    for(int i = 0; i < n; i++) {
        int x;  cin >> x;
        s1 += char('0' + --x);
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;  cin >> x;
        s2 += char('0' + --x);
    }
    set<pair<string, string>> vis;
    string a = s1, b = s2;
    while(!a.empty() and !b.empty())
    {
        vis.insert({a, b});
        vis.insert({b, a});
        c++;
        if(a[0] > b[0])
            a += b[0], a += a[0];
        else
            b += a[0], b += b[0];
        a.erase(a.begin());
        b.erase(b.begin());
        if(vis.count({a, b}) or vis.count({b, a}))
            return cout << "-1", 0;
    }
    cout << c << ' ' << (a.empty() ? '2' : '1');
}