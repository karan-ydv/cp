#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s[n];
  for(auto &x: s) cin >> x;
  for(int j = 0; j < m; j++) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += s[i][j] == '#';
    }
    cout << sum << ' ';
  }
}