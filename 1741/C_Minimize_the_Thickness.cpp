#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;	cin >> t;
  while(t--)
  {
    int n;	cin >> n;
    int a[n];
    for(int &x: a)  cin >> x;
    
    int ans = n, total = accumulate(a, a + n, 0);

    for(int i = 0, s = 0; i < n - 1; i++)
    {
      s += a[i];
      if (total % s) continue;
      int thickness = i + 1, sum = 0;
      for (int j = i + 1, prev = i; j < n; j++)
      {
        sum += a[j];
        if (sum == s)
        {
          thickness = max(thickness, (j - prev));
          sum = 0;
          prev = j;
        }
      }
      if (sum == 0) ans = min(ans, thickness);
    }
    cout << ans << '\n';
  }
}
