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
    int n;	cin >> n;
    int ans[n];
    vector<bool> taken(n);
    for(int i = 1, c = 0; i <= n; i++)
    {
      if (taken[i]) continue;
      for(int j = 1; i * j <= n; j <<= 1)
      {
        taken[i * j] = true;
        ans[c++] = i * j;
      }
    }
    for(int &x: ans) cout << x << " ";
    cout << '\n';
  }
}

/* 

1 2 4 8 16 32 64 48
3 6 12 24
5 10 20 40
7 14 28 56
9 18 36
11 22 44
13 26 52
15 30 60
17 34
19 38
21 42
23 46
25 50
27 54
29 58
31 62

33
35
37
39
41
43
45
47
49
51
53
55
57
59
61
63

24 12 6 3 9 18 36 5 10 15 20 25 30 35 40 45 50 55 60
3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48



// 2 * 2 * 2 * 2 * 2 * 2
// 3 * 16
// 48 24 16 12 8

// 2 * 2 * 3 * 3

*/
