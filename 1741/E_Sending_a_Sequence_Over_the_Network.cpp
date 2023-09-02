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
    int a[n + 1];
    for(int i = 1; i <= n; i++)
      cin >> a[i];

    vector<bool> dp(n + 1, false);
    dp[0] = true;
    // dp[i] = true if a[1..i] is valid sequence
    for(int i = 0; i <= n; i++)
    {
      if (i - a[i] - 1 >= 0)  dp[i] = dp[i] || dp[i - a[i] - 1];
      if (i + a[i] + 1 <= n)  dp[i + a[i] + 1] = dp[i];
    }
    if (dp[n])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
