#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  // check if n is a Harshad number
  int sum = 0, x = n;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  if (n % sum == 0) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}
