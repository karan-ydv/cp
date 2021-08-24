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
        map<int, vector<int>> mp;
        for(int i = 1; i <= n; i++)
        {
            int x;  cin >> x;
            mp[x].emplace_back(i);
        }
        int ans = 0;
        for(auto &[a, v]: mp)
        {
            int sum = n * v.size() + v.size();
            for(int x: v)   sum -= x;
            for(int x: v)
            {
                sum -= (n - x + 1);
                ans += x * sum;
            }
        }
        cout << ans << '\n';
    }
}