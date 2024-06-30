#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, T;
  cin >> N >> T;

  string S;
  cin >> S;

  vector<int> X(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }

  vector<pair<int, char>> arr;
  for (int i = 0; i < N; ++i) {
    arr.emplace_back(X[i], S[i]);
  }
  sort(arr.begin(), arr.end());

  multiset<int> f;
  int ans = 0;
  for (const auto& [x, s] : arr) {
    if (s == '0') {
      int adjusted_x = x - T;
      auto it = f.lower_bound(adjusted_x);
      ans += distance(it, f.end());
    } else {
      int adjusted_x = x + T;
      f.insert(adjusted_x);
    }
  }

  cout << ans << endl;
  return 0;
}