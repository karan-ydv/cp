#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;	cin >> t;
  while(t--)
  {
    int n, k; string s;
    cin >> n >> k >> s;

    s = "!" + s;
    vector<int> ans(n + 1, 0);

    int _m = 2;

    while(_m --> 0)
    {
      vector<vector<int>> pref(n + 1, vector<int>(k + 1, 0));
      vector<int> dp(n + 1, -1);

      // pref[i][j] = max length of continuous zeroes ending at i by flipping j ones
      for(int i = 1; i <= n; i++)
      {
        if(s[i] == '0') pref[i][0] = pref[i - 1][0] + 1;
        for(int j = 1; j <= k; j++)
          pref[i][j] = pref[i - 1][j - (s[i] - '0')] + 1;
      }

      // pref[i][j] = max length of continuous zeroes ending upto i by flipping at most j ones
      for(int i = 1; i <= n; i++)
      for(int j = 0; j <= k; j++)
        pref[i][j] = max(pref[i][j], pref[i - 1][j]);
      
      for(int i = 1; i <= n; i++)
      {
        int zeroes = 0;
        dp[0] = max(dp[0], pref[i][k]);
        // dp[len] = max length of continuous zeroes before or after a segment of ones of length len
        for(int j = i, len = 1; j <= n; j++, len++)
        {
          zeroes += (s[j] == '0');
          if (zeroes > k) break;
          dp[len] = max(dp[len], pref[i - 1][k - zeroes]);
        }
      }

      for(int a = 1; a <= n; a++)
      for(int i = 0; i <= n; i++)
        if (dp[i] >= 0) ans[a] = max(ans[a], i + a * dp[i]);

      reverse(s.begin() + 1, s.end());
    }

    for(int i = 1; i <= n; i++)
      cout << ans[i] << " \n"[i == n];
  }
}
