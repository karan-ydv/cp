#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s[n];
    for (auto &x : s)
        cin >> x;
    auto fun = [&](string &str) {
        for (int i = 1; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < m and c < 2; j++)
                c += s[i][j] != str[j];
            if (c > 1)
                return false;
        }
        return true;
    };
    string ans = s[0];
    for (int j = 0; j < m; j++)
    {
        char ch = ans[j];
        for (char c = 'a'; c <= 'z'; c++)
        {
            ans[j] = c;
            if (fun(ans))
                return cout << ans, void();
        }
        ans[j] = ch;
    }
    cout << "-1";
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
}