#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int ans = -1;
  for(int i = n - 1; i >= 0; i--)
  {
    if(s[i] == 'a')
    {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
}
