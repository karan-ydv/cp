#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 4e5 + 69;
int a[N], p[N], ans[N];

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    p[2 * i] = a[i];
    p[2 * i + 1] = a[i];
  }
  ans[0] = -1;
  for(int i = 1; i <= 2 * n + 1; i++)
  {
    ans[i] = ans[p[i]] + 1;
    cout << ans[i] << '\n';
  }
}