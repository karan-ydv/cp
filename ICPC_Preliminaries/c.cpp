#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e6+69;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   int n, a, b;
    cin >> n >> s >> a >> b;
    if(s.find('B') == n)
        return cout << '0', 0;
    if(s.find('R') == n)
        return cout << a, 0;
    int k = a / b;
    vector<int> v;
    int sz = 0;
    char prev = s[0];
    int ans = 0, blue = 0, red = 0;
    for(auto c: s)
    {
        if(c != prev) {
            if(prev == 'B')
                v.emplace_back(0), blue++;
            else
                v.emplace_back(sz), red += sz;
            sz = 0;
        }
        prev = c;
        sz++;
    }
    if(prev == 'B')
        v.emplace_back(0), blue++;
    else 
        v.emplace_back(sz), red += sz;
    // for(int x: v)
    //     cerr << x << ' '; cerr <<'\n';
    vector<int> w;
    w.push_back(v[0]);
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i] <= k)
        {
            ans += v[i] * b;
            v[i] = 0;
        }
        if(v[i] != w.back())
            w.push_back(v[i]);
    }
    // for(int x: w)
    //     cerr << x << ' '; cerr <<'\n';
    
    int cnt = 0;
    for(int x: w) cnt += x == 0;
    if(w.size() > 1) if(w[0] == 0 and w.back() == 0)
        cnt--;
    // cerr << ans << ' ' << cnt << '\n';
    ans += cnt * a;
    cout << ans;
}