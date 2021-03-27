#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A[1001];
	A[0] = 0;
	for(int i = 1; i <= 1000; i++) {
		A[i] = A[i - 1]; 
		for(int k = 0; k <= i; k++)
			A[i] += ((k + i) == (k ^ i));
	}
	int t;	cin >> t;
	while(t--)
	{
		int n, q;	cin >> n >> q;
		while(q--)
		{
			int l, r;	cin >> l >> r;
			cout << A[r]-A[l - 1] << '\n';
		}
	}
}