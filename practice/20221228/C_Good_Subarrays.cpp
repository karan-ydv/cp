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
    int n, ans = 0;
    string s;
    cin >> n >> s;
    s = " " + s;
    int a[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; i++)
      a[i] = a[i - 1] + s[i] - '0';
    for (int i = 1; i <= n; i++)
      a[i] -= i;
    map<int, int> mp;
    for(int i = 1; i <= n; i++)
    {
      mp[a[i]]++;
    }
    for(auto [x, f] : mp)
      ans += (f * (f - 1)) / 2;
    cout << ans + mp[0] << '\n';
  }
}
