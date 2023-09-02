#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;  cin >> n;
  int x[n], y[n], z[n];
  for(int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> z[i];
  int dp[1 << n][n];

  for(int i = 0; i < (1 << n); i++)
    for(int j = 0; j < n; j++)
      dp[i][j] = 1e18;
  // dp[s][i] = min cost to visit all cities in s and end at i
  
  dp[1][0] = 0;

  for(int s = 1; s < (1 << n); s++)
  {
    for(int i = 0, p = 1; p < s; i++, p <<= 1) if(s & p)
      for(int j = 0, q = 1; q < s; j++, q <<= 1) if (s & q)
        dp[s][i] = min(dp[s][i], dp[s ^ p][j] + abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0LL, z[i] - z[j]));
  }
  int ans = 1e18;
  for(int i = 1; i < n; i++) {
    ans = min(ans, dp[(1 << n) - 1][i] + abs(x[i] - x[0]) + abs(y[i] - y[0]) + max(0LL, z[0] - z[i]));
  }
  cout << ans << endl;
}