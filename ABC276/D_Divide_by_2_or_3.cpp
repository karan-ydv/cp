#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solve(vector<int> a)
{
  int n = a.size();

  if (all_of(a.begin(), a.end(), [a](int x) { return x == a[0]; }))
    return 0;

  int gcd = a[0];
  for (int i = 1; i < n; i++)
    gcd = __gcd(gcd, a[i]);
  
  for (int i = 0; i < n; i++)
    a[i] /= gcd;
  
  vector<int> two(n), three(n);

  for (int i = 0; i < n; i++)
  {
    while (a[i] % 2 == 0)
    {
      a[i] /= 2;
      two[i]++;
    }
    while (a[i] % 3 == 0)
    {
      a[i] /= 3;
      three[i]++;
    }

    if (a[i] != 1)
      return -1;
  }
  
  int ans = 0;
  int min_two = *min_element(two.begin(), two.end());
  int min_three = *min_element(three.begin(), three.end());
  for (int i = 0; i < n; i++)
    ans += two[i] - min_two + three[i] - min_three;
  
  return ans;
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cout << solve(a) << endl;
}
