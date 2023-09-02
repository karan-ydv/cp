#include <vector>
#include <iostream>
#define int int64_t
using namespace std;

long long solve(int N, int K, vector<int> A) {
  long long ans = 0;
  for(int i = 0; i < K; i++) {
    long long sum = 0;
    for(int j = i; j < N; j += K) {
      sum += A[j];
    }
    for(int j = i; j < N; j += K) {
      ans += A[j] * (sum - A[j]);
    }
  }
  return ans / 2;
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;	cin >> t;
  while(t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
    }
    cout << solve(n, k, v) << '\n';
  }
}