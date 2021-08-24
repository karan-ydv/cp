#include <bits/stdc++.h>
#define int int64_t
using namespace std;

string a[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
const int N = 2e5+69;
int pref[6][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n, m;  cin >> n >> m >> s;
    s = "!" + s;
    for(int i = 0; i < 6; i++)
    {
        while(a[i].length() < n)
            a[i] += a[i];
        a[i] = "!" + a[i];
        for(int j = 1; j <= n; j++)
            pref[i][j] = pref[i][j - 1] + (s[j] != a[i][j]);
    }

    while(m--)
    {
        int l, r;   cin >> l >> r;  l--;
        int ans = 1e9;
        for(int i = 0; i < 6; i++)
            ans = min(ans, pref[i][r] - pref[i][l]);
        cout << ans << '\n';
    }
}