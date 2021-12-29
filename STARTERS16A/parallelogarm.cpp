#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int cross(int x, int y, int a, int b) {
    int res = x * b - y * a;
    if(res < 0) res *= -1;
    return res;
}

int solve()
{
    int n;  cin >> n;   int x[n], y[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
    map<pair<int, int>, vector<pair<int, int>>> mp;
    for(int i = 0; i < n; i++)  for(int j = i + 1; j < n; j++)
        mp[{x[i] + x[j], y[i] + y[j]}].emplace_back(i, j);
    
    int ans = 0;
    for(auto &[p, v]: mp)
    for(int i = 0; i < v.size(); i++)
    for(int j = i + 1; j < v.size(); j++)
    ans = max(ans, cross(x[v[i].first] - x[v[j].first], y[v[i].first] - y[v[j].first],
                         x[v[i].second] - x[v[j].first], y[v[i].second] - y[v[j].first]));
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << solve();
}