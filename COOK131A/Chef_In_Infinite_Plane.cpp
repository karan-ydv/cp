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
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            if(mp[x] < x - 1) {
                ans ++;
                mp[x]++;
            }
        }
        cout << ans << '\n';
    }
}