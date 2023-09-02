#include <vector>
#include <iostream>
#include <string>
#define int int64_t
using namespace std;

int toyShop (int N, int M, string toys, vector<int> costOfToys) {
  cerr << N << ' ' << M << ' ' << toys;
  int ans = 0;
  for(char c = 'a'; c <= 'd'; c++) {
    int l = 0, cost = 0;
    for(int r = 0; r < N; r++)
    {
      if (toys[r] != c)
        cost += costOfToys[toys[r] - 'a'];

      while(cost > M)
      {
        if (toys[l] != c)
          cost -= costOfToys[toys[l] - 'a'];
        l++;
      }
      cerr << l << ' ' << r <<  ' ' << cost << '\n';
      ans = max(ans, r - l + 1);
    }
  }
  return ans;
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--)
  {
    int n, m; string s;
    cin >> n >> m >> s;
    vector<int> v(26);
    for(int i = 0; i < 26; i++)
      cin >> v[i];
    cout << toyShop(n, m, s, v) << '\n';
  }
}