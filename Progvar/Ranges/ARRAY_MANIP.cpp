#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5;
int A[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,	m;	cin >> n >> m;
	while(m--) {
		int l, r, v;	cin >> l >> r >> v;
		A[l] += v;
		A[r + 1] -= v;
	}
	int mx = 0;
	for(int i = 1; i <= n; i++) {
		A[i] += A[i - 1];
		mx = max(mx, A[i]);
	}
	cout << mx;
}