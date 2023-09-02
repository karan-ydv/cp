#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p, ans;
  cin >> n >> m >> p;
  if (n < m)
    ans = 0;
  else
    ans = 1 + (n - m) / p;
  cout << ans << '\n';
}
