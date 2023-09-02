#include <iostream>
#include <vector>
#include <algorithm>
#define int int64_t
using namespace std;

long long solve(int n, int m, int k, vector<int> closed, vector<int> cost) {
  vector<bool> a(n + 1, true);
  for(int i = 0; i < m; i++) {
    a[closed[i]] = false;
  }
  if (a[0] == false) return -1;
  vector<int> v;
  v.emplace_back(1);
  for(int i = 1; i <= n; i++) {
    if (a[i])
  }
}
// 0 1 2 3 4 5 6
// 1 0 1 0 1 1 1
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;	cin >> t;
  while(t--)
  {
    int n, m, k;  cin >> n >> m >> k;
    int closed
  }
}