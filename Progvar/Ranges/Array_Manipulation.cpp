#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7;

int n, m;
int t[2 * N];

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	while(m--)
	{
		int l, r, v;	cin >> l >> r >> v;
		modify(l - 1, r, v);
	}
	int mx = 0;
	for(int i = 0; i < n; i++)
		mx = max(mx, query(i));
	cout << mx;
}