#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int ans = max_element(a, a + n) - a;
  cout << ans + 1 << '\n';
}