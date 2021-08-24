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
        int n;	cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            int x;  cin >> x;
            mp[x]++;
        }
        int ans = 0;
        for(auto [x, f]: mp) {
            ans += f * (n - f);
        }
        cout << ans << '\n';
    }
}