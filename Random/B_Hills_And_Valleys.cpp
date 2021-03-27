#include <bits/stdc++.h>
// #define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		int A[n];
		for(int i = 1; i <= n; i++)
			cin >> A[i];
		A[0] = A[1];
		A[n+1] = A[n];
		vector<int> v(n + 2);
		int sum = 0;
		for(int i = 2; i <= n - 1; i++) {
			v[i] = (A[i] < A[i - 1] and A[i] < A[i + 1]) or (A[i] > A[i - 1] and A[i] > A[i + 1]);
			sum += v[i];
		}
		int ans = sum;
		for(int i = 2; i <= n - 1; i++) {
			int tmp = A[i];
			int x = v[i-1], y = v[i], z = v[i + 1];
			int a, b, c, j;

			A[i] = -2e9;
			j = i - 1;	a = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i;		b = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i + 1;	c = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			ans = min(ans, sum - (x + y + z) + a + b + c);

			A[i] = 2e9;
			j = i - 1;	a = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i;		b = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i + 1;	c = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			ans = min(ans, sum - (x + y + z) + a + b + c);

			A[i] = A[i - 1];
			j = i - 1;	a = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i;		b = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i + 1;	c = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			ans = min(ans, sum - (x + y + z) + a + b + c);

			A[i] = A[i + 1];
			j = i - 1;	a = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i;		b = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			j = i + 1;	c = (A[j] < A[j - 1] and A[j] < A[j + 1]) or (A[j] > A[j - 1] and A[j] > A[j + 1]);
			ans = min(ans, sum - (x + y + z) + a + b + c);

			A[i] = tmp;
		}
		cout << ans << '\n';
	}
}