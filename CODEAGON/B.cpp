#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<pair<string, int>> v;
    v.reserve(2 * n);
    for(int i = 0; i < n; i++)
    {
        string a, b;    cin >> a >> b;
        v.emplace_back(a, 1);
        v.emplace_back(b, -1);
    }
    sort(v.begin(), v.end());
    string ans;
    int cnt = 0, mx = -1;
    for(auto [a, b]: v)
    {
        cnt += b;
        // cerr << a << ' ' << b << ' ' << cnt << '\n';
        if(cnt > mx)
        {
            mx = cnt;
            ans = a;
        }
    }
    cout << ans;
    // cerr << mx;
}