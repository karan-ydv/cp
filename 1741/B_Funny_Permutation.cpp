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
    if (n == 3)
    {
      cout << "-1\n";
      continue;
    }
    int a[n];
    iota(a, a + n, 1);
    reverse(a, a + n);
    if (n & 1) reverse(a, a + n / 2 + 1);
    for (int i = 0; i < n; i++)
      cout << a[i] << ' ';
    cout << '\n';
  }
}
