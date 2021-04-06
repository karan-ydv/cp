#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;	cin >> n >> q;
	int A[n + 1] = {0};
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
		A[i] ^= A[i - 1];
	}
	while(q--)
	{
		int a, b;	cin >> a >> b;
		cout << (A[b] ^ A[a - 1]) << '\n';
	}
}