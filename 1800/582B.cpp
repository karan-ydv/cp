#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;   cin >> n >> t;
    map<int, int> mp;
    vector<int> a(n);
    for(int &x: a)  cin >> x;
    int ans = 0;
    for(int x: a) {
        mp[x]++;
        ans = max(ans, mp[x] * t);
    }
    vector<int> v;
    for(int i = 0; i < min((int)2e6, n * t); i++) {
        int x = a[i % n];
        auto itr = upper_bound(v.begin(), v.end(), x);
        if(itr == v.end())
            v.emplace_back(x);
        else
            *itr = x;
        ans = max(ans, (int)v.size() + mp[v.back()] * (t - (i + n) / n));
    }

    cout << ans;
}