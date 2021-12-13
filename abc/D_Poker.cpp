#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int score(string s)
{
    int a[9]{};
    iota(a, a + 9, 1);
    for(char c: s) a[c - '1'] *= 10;
    return accumulate(a, a + 9, 0LL);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k; string s, t;
    cin >> k >> s >> t;

    vector<int> f(9, k);
    for(char c: s)  f[c - '1'] --;
    for(char c: t)  f[c - '1'] --;

    long double ans = 0;
    for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
    {
        s[4] = char('1' + i);
        t[4] = char('1' + j);
        int n = i == j ? f[i] * (f[i] - 1) : f[i] * f[j];
        if(score(s) > score(t))
            ans += n;
    }
    ans /= (9 * k - 8) * (9 * k - 9);
    cout << fixed << setprecision(20) << ans;
}