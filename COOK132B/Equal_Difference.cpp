#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            mp[x]++;
        }
        if(n <= 2)
        {
            cout << "0\n";
            continue;
        }
        int ans = n - 2;
        for(auto [x, f]: mp)
        {
            ans = min(ans, n - f);
        }
        cout << ans << '\n';
    }
}