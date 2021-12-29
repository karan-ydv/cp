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
        string key, s;
        cin >> key >> s;
        int ans = 0;
        for(int i = 1; i < (int)s.length(); i++) {
            int a = key.find(s[i]);
            int b = key.find(s[i - 1]);
            ans += abs(a-b);
        }
        cout << ans << '\n';
    }
}