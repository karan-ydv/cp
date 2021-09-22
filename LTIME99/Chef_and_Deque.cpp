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
        int n, m;   cin >> n >> m;
        int a[n + 1] = {};
        map<int, vector<int>> mp1, mp2;
        mp1[0].emplace_back(0);
        mp2[0].emplace_back(0);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            (a[i] += a[i - 1]) %= m;
            mp1[a[i]].emplace_back(i);
            mp2[a[i]].emplace_back(n - i);
        }
        int ans = 1e9;
        for(auto &[x, v1]: mp1)
        {
            auto &v2 = mp2[x];
            int k = v1.size();
            for(int i = 0; i < k; i++)
            for(int j = i + 1; j < k; j++)
            {
                if((v1[i] | v2[j]) == v2[j])
                ans = min(ans, (int)__builtin_popcount(v2[j]));
            }
        }
        if(ans == 1e9)
            ans = -1;
        cout << ans << '\n';
    }
}