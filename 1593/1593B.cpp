#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int fun(string a, string &s)
{
    int ans = 0;
    int i = s.find(a[0]);
    if(i == string::npos)
        return 1e9;
    ans += i;
    int j = s.find(a[1], i + 1);
    if(j == string::npos)
        return 1e9;
    ans += j - i - 1;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a[] = {"00", "52", "05", "57"};
    int t;	cin >> t;
    while(t--)
    {
        string s;   cin >> s;
        reverse(s.begin(), s.end());
        int ans = 1e9;
        for(auto x: a)
            ans = min(ans, fun(x, s));
        cout << ans << '\n';
    }
}