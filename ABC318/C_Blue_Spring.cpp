#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d, p;
  cin >> n >> d >> p;
  int f[n + 2];
  for(int i = 1; i <= n; i++) cin >> f[i];
  f[0] = f[n + 1] = 0;
  sort(f + 1, f + n + 1, greater<int>());
  partial_sum(f, f + n + 2, f);
  int ans = 1e18;
  for(int i = 0; i <= n + 1; i++)
    ans = min(ans, p * ((i + d - 1) / d) + f[n + 1] - f[i]);
  cout << ans;
}
