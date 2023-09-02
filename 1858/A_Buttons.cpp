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
    int a, b, c;
    cin >> a >> b >> c;

    int first = a + (c + 1) / 2;
    int second = b + c / 2;
    
    // clog << first << ' ' << second << "\n";

    if (second >= first)
      cout << "Second";
    else
      cout << "First";
    cout << "\n";
  }
}
