#include <iostream>
#include <string>
#define int int64_t
using namespace std;

// S M L
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;	cin >> t;
  while(t--)
  {
    string a, b;
    cin >> a >> b;
    if(a == b)
      cout << "=";
    else if(a.back() == b.back())
    {
      if (a.back() == 'L')
        cout << (a.length() > b.length() ? ">" : "<");
      else
        cout << (a.length() < b.length() ? ">" : "<");
    }
    else
      cout << (a.back() < b.back() ? ">" : "<");
    cout << '\n';
  }
}
