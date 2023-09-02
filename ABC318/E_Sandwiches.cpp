#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  for(int i = 0; i < n; i++)
  {
    int x;  cin >> x;
    mp[x].push_back(i);
  }
  int ans = 0;
  for(auto [x, v]: mp)
  {
    int m = v.size(), sum = v[0];
    for(int i = 1; i < m; i++)
    {
      ans += (v[i] - 1) * i - sum - i * (i - 1) / 2;
      sum += v[i];
    }
  }
  cout << ans << '\n';
}
