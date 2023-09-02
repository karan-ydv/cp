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

    function<int(int, int)> merge_sort = [&](int l, int r) -> int
    {
      int len = r - l;
      if (len == 1) return 0;
      len /= 2;
      int lx = merge_sort(l, l + len);
      int rx = merge_sort(l + len, r);
      if (lx == -1 or rx == -1) return -1;
      int ans = -1;
      if (a[l + len - 1] < a[l + len])
        ans = lx + rx;
      else if (a[r - 1] < a[l])
        ans = lx + rx + 1;
      inplace_merge(a + l, a + l + len, a + r);
      return ans;
    };

    cout << merge_sort(0, n) << '\n';
  }
}
