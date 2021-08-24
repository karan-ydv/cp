#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 18;
int dp[1 << N][100];
int fact[20], freq[10];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < 20; i++)
        fact[i] = fact[i - 1] * i;

    int n, m; cin >> n >> m;
    string s = to_string(n);
    int p = s.length();

    // doesn't start with 0
    for (int i = 0, b = 1; i < p; i++, b <<= 1)
    {
        freq[s[i] - '0']++;
        if (s[i] != '0') 
        dp[b][(s[i] - '0') % m] = 1;
    }

    for (int i = 1; i < (1 << p); i++)
        for (int k = 0, b = 1; k < p; k++, b <<= 1)
            if (!(i & b)) for (int j = 0; j < m; j++)
                dp[i | b][(j * 10 + s[k] - '0') % m] += dp[i][j];

    int ans = dp[(1 << p) - 1][0];
    for (int i = 0; i < 10; i++)
        ans /= fact[freq[i]];
    cout << ans;
}