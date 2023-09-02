#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, N;
  cin >> n >> m;
  N = n + m + 2;
  int x[N], y[N];
  x[0] = y[0] = x[n + 1] = y[n + 1] = 0;
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> y[i];
  for(int i = 1; i <= m; i++)
    cin >> x[n + i + 1] >> y[n + i + 1];

  double ans = 1e18;
  double dp[1 << N][N];
  // dp[S][i] = minimum time needed if we are at i and we have visited the set S
  
  int fullset = (1 << N) - 1;
  int cityset = (1 << (n + 2)) - 1;
  int boosterset = fullset ^ cityset;

  fill_n(&dp[0][0], (1 << N) * (N), 1e18);
  dp[1][0] = 0;

  for (int s = 1; s < (1 << N); s++)
  {
    for (int i = 0; i < N; i++) if (s & (1 << i))
    for (int j = 0; j < N; j++) if ((s & (1 << j)) == 0)
    {
      double dist = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      int speed = 1 << __builtin_popcountll(s & boosterset);
      dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + dist / speed);
    }
    if ((s & cityset) == cityset)
      ans = min(ans, dp[s][n + 1]);
  }

  cout << fixed << setprecision(10) << ans << '\n';
}
