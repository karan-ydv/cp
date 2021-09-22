#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solve(string s)
{
    int n = s.length();
    s += "!";
    vector<int> v;
    for(int i = 0; i < n; )
    for(int j = i; j <= n; j++) if(s[j] != s[i])
    {
        v.emplace_back(j - i);
        i = j;
        break;
    }
    for(int x: v) cerr << x << ' ';
    int ans = 0;
    for(int i = 0; i + 1 < v.size(); i++)
        ans += min(v[i], v[i + 1]);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    cout << solve(s);
}