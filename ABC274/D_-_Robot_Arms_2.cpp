#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5 + 69;
bitset<2 * N> bx, by;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  int a[n]; for(int &v: a) cin >> v;
  bx[N + a[0]] = 1;
  by[N + a[1]] = 1;
  by[N - a[1]] = 1;
  for(int i = 2; i < n; i++)
  {
    if (i % 2 == 0)
    {
      bx = (bx << a[i]) | (bx >> a[i]);
    }
    else
    {
      by = (by << a[i]) | (by >> a[i]);
    }
  }
  cout << (bx[N + x] && by[N + y] ? "Yes" : "No") << '\n';
}
