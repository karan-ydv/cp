#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<array<int, 4>> arr(n);
  for(int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    arr[i] = {a, b, c, d};
  }
  int ans = 0;
  for(int x = 0; x < 100; x++)
  for(int y = 0; y < 100; y++)
  for(auto [a, b, c, d]: arr)
  {
    bool flag = (x + 0.5 <= b && x + 0.5 >= a) && (y + 0.5 <= d && y + 0.5 >= c);
    ans += flag;
    if (flag) break;
  }
  cout << ans << '\n';
}
