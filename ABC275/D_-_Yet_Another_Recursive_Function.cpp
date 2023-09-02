#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int f(int n)
{
  if(n == 0) return 1;
  return f(n / 2) + f(n / 3);
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 1; i < 1000; i++) {
    clog << i << ' ' << f(i) << '\n';
  }
}
