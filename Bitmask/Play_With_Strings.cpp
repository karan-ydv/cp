#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int A[3], n;
	cin >> n >> A[0] >> A[1] >> A[2] >> s;
	sort(A, A + 3);
	int ans = 0;
	do
	{
		int t = 0, mx = 0;
		for(char c: s)
		{
			t += A[(c - 'a') % 3];
			mx = max(mx, t);
			if(t < 0)	t = 0;
		}
		ans = max(ans, mx);
	}
	while(next_permutation(A, A + 3));
	cout << ans;
}