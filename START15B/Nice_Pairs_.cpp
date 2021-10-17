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
        for(int i = 0; i < n; i++) {
            for(int j = i + 1;  j < min(i + 10, n); j++) {
                ans += (j - i) == abs(s[j] - s[i]);
            }
        }
        cout << ans << '\n';
    }
}