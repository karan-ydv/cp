#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int64_t t;
  cin >> t;

  while (t--) {
    int64_t n, m;
    cin >> n >> m;

    int64_t count = 0;

    for (int64_t b = 1; b <= m; ++b) {
      int64_t upper_bound = n / b;
      count += (upper_bound + 1) / b;
      if (b == 1) {
        count -= 1;
      }
    }

    cout << count << '\n';
  }
}

/*
n = 10, m = 10

b = 1
  upper_bound = 10
  d = 1 * gcd(10, 1) = 1
  count += 10 / 1 = 10

b = 2
  upper_bound = 10
  d = 2 * gcd(10, 2) = 2
  count += 10 / 2 = 5f


n + m

mb + b = k * gcd(a, b) * b
b * (m + 1) = k * gcd(a, b) * b
m + 1 = k * gcd(a, b)
m = k * m - 1

a+b is a multiple of b * gcd(a,b)

a = k * b

(k + 1) is a multiple of k

how many k exist?

10, 8

b = 1
  a = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

b = 5

3 5

b = 1
  a = 1, 2, 3
b = 2
  a = 1, 2
b = 3
  a = 1


10 + 2 = 2 * gcd(10, 2)
2 * (5 + 1) = 2 * gcd(2 * 5, 2)



b * (k + 1) = m * b * gcd(kb, b)
k + 1 = m * b

a = k * b < n
1, n / b
2, n / b + 1
*/
