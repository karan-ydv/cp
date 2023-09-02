#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (prev_permutation(a.begin(), a.end()))
  {
    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
  }
  else
    cout << -1 << endl;
}
