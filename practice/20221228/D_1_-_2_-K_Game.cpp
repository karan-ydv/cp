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
    int n, k, ans;
    cin >> n >> k;
    bool a[3];
    a[0] = 0;
    a[1] = a[2] = 1;

    if (n < 3) ans = a[n];
    else if (k % 3 != 0 || k > n)
      ans = n % 3 != 0;
    else
    {
      n = (n - k) % (k + 1);
      if (n == 0)
        ans = 1;
      else
        ans = n % 3 != 1;
    }
    if (ans == 1)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
}
