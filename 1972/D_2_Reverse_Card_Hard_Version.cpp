#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 4e6 + 69;
int spf[N];	// smallest prime factor
void sieve()
{
	iota(spf, spf + N, 0);
	for(int i = 4; i <= N; i += 2)  spf[i] = 2;
	for(int i = 3; i * i <= N; i += 2)
	{
		if(spf[i] == i)	for(int j = i * i; j < N; j += i)
		if(spf[j] == j)	spf[j] = i;
	}
}

int count(int N, int A, int B) {
  int n = N;
	vector<int> f;
  f.push_back(1LL);

  int c = 0;

	while(n != 1)
	{
		int p = spf[n];
		while(spf[n] == p)
    {
      for (int factor : f) {
        int b = factor * p;
        int a = n - b;

        if (a == 0) break;

        cerr << n << " -> " << b << '\n';
        if (a <= A and b <= B and b * gcd(a, b) == N ) c += 1;

        f.push_back(b);
      }

      n /= p;
    }
	}
  cerr << N << ' ' << A << ' ' << B << " : " << c << '\n';
	return c;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int ans = 0;

    for (int x = 2; x <= n + m; ++x) {
      ans += count(x, n, m);
    }

    cout << ans << '\n';
    cerr << '\n';
  }
}
