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
    int n, m, d;
    cin >> n >> m >> d;
    int a[m + 2];
    for(int i = 1; i <= m; i++) cin >> a[i];

    a[0] = 1 - d;
    a[m + 1] = n + 1;
    int sum = 0;
    for(int i = 1; i <= m + 1; i++)
      sum += (a[i] - a[i - 1] - 1) / d;

    int ans = n + 1, cnt = 0;
    for(int i = 1; i <= m; i++)
    {
      int x = (a[i + 1] - a[i] - 1) / d;
      int y = (a[i] - a[i - 1] - 1) / d;
      int z = (a[i + 1] - a[i - 1] - 1) / d;

      int temp = sum - x - y + z + m - 1;

      if (temp < ans)
      {
        ans = temp;
        cnt = 0;
      }
      if (temp == ans) cnt++;
    }
    cout << ans << ' ' << cnt << "\n";
  }
}

// d x x d x x d
