#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int x;  cin >> x;
        mp[x % 200]++;
    }
    int ans = 0;
    for(auto [a, f]: mp)
    {
        ans += f * (f - 1) / 2;
    }
    cout << ans;
}