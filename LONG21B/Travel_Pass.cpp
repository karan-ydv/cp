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
        string s; int n, a, b, ans = 0;
        cin >> n >> a >> b >> s;
        for(char c: s) ans += c - '0' ? b : a;
        cout << ans << '\n';
    }
}