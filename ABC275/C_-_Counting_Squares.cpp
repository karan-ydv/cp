#include <bits/stdc++.h>
#define int int64_t
#define for(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s[9];
  for(i, 0, 9)
    cin >> s[i];
  int ans = 0;

  for(x1, 0, 9) for(y1, 0, 9)
  for(x3, 0, 9) for(y3, 0, 9)
  {
    if(s[x1][y1] != '#' or s[x3][y3] != '#')  continue;
    if (x1 == x3 and y1 == y3) continue;

    float xc = (x1 + x3) / 2.0;
    float yc = (y1 + y3) / 2.0;
    float xd = (x3 - x1) / 2.0;
    float yd = (y3 - y1) / 2.0;
    float x2 = xc - yd;
    float y2 = yc + xd;
    float x4 = xc + yd;
    float y4 = yc - xd;
    if (x2 - (int)(x2) != 0 or y2 - (int)(y2) != 0 or x4 - (int)(x4) != 0 or y4 - (int)(y4) != 0) continue;
    if (x2 < 0 or x2 >= 9 or y2 < 0 or y2 >= 9 or x4 < 0 or x4 >= 9 or y4 < 0 or y4 >= 9) continue;
    if (s[(int)(x2)][(int)(y2)] != '#' or s[(int)(x4)][(int)(y4)] != '#') continue;
    ans++;
  }
  cout << ans / 4 << '\n';
}
