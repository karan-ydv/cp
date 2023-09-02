#include <bits/stdc++.h>
#define for(i, a, b) for (int i = (a); i < (b); ++i)
#define int int64_t
using namespace std;

const int N = 169;
int f[N], p[N][11];

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  
  for(i, 0, n) for(j, 0, 10) {
    int x;
    cin >> x;
    f[i] <<= 1;
    f[i] |= x;
  }

  for(i, 0, n) for(j, 0, 11) cin >> p[i][j];

  int ans = -1e18;
  for(i, 1, 1 << 10) {
    int sum = 0;
    for(j, 0, n) {
      int x = __builtin_popcount(f[j] & i);
      sum += p[j][x];
    }
    ans = max(ans, sum);
  }
  cout << ans;
}
