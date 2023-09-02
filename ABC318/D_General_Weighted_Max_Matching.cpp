#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int w[16][16];
int dp[1 << 16];

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
  for(int j = i + 1; j < n; j++)
  {
    cin >> w[i][j];
    w[j][i] = w[i][j];
  }
  int ans = 0;
  for(int i = 0; i < (1 << n); i++)
  {
    for(int j = 0; j < n; j++) if ((i & (1 << j)) == 0)
    for(int k = j + 1; k < n; k++) if ((i & (1 << k)) == 0)
    {
      int &x = dp[i | (1 << k) | (1 << j)];
      x = max(x, dp[i] + w[j][k]);
      ans = max(ans, x);
    }
  }
  cout << ans << '\n';
}
