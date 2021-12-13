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
        int n; string s;
        cin >> n >> s;
        int ans = 0;
        for(char c: s)
            ans += c - '0';
        for(int i = 0; i + 1 < n; i++)
            if(s[i] != '0') ans++;
        cout << ans << '\n';
    }
}