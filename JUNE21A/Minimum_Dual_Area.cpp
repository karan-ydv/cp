#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

const int N = 1e5 + 69;
int suffMax[N], suffMin[N];

int minArea(vector<pair<int, int>> &v)
{
    int m = v.size();
    suffMax[m] = -1, suffMin[m] = 2e9;
    for (int i = m - 1; i >= 0; i--)
    {
        suffMax[i] = max(v[i].second, suffMax[i + 1]);
        suffMin[i] = min(v[i].second, suffMin[i + 1]);
    }

    int ans = (v[m - 1].first - v[0].first) * (suffMax[0] - suffMin[0]);
    int prefMax = v[0].second, prefMin = v[0].second;
    for (int i = 1; i < m; i++)
    {
        int x = (v[i - 1].f - v[0].f) * (prefMax - prefMin);
        int y = (v[m - 1].f - v[i].f) * (suffMax[i] - suffMin[i]);
        ans = min(ans, x + y);
        prefMax = max(prefMax, v[i].second);
        prefMin = min(prefMin, v[i].second);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (auto &[x, y] : v)  cin >> x >> y;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        int ans = minArea(v);
        for (auto &[x, y] : v)  swap(x, y);
        sort(v.begin(), v.end());
        ans = min(ans, minArea(v));
        cout << ans << '\n';
    }
}