#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int M = 998244353;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a %= M;
  b %= M;
  c %= M;
  d %= M;
  e %= M;
  f %= M;
  int p1 = a * b % M * c % M;
  int p2 = d * e % M * f % M;
  int ans = p1 + M - p2;
  ans %= M;
  cout << ans << '\n';
}