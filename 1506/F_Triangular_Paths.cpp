#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		pair<int, int> a[n];
		for(int i = 0; i < n; i++)	cin >> a[i].f;
		for(int i = 0; i < n; i++)	cin >> a[i].s;
		sort(a, a + n);
		auto cost = [&](pii a, pii b)
		{
			int cst = 0;
			if(b.f - a.f == abs(a.s - b.s)) {
				return (abs(a.s - b.s) + ) / 2;
			}
			return 0;
		};
		int ans = 0;
		for(int i = 1; i < n; i++) {
			ans += cost(a[i - 1], a[i]);
		}
		cout << ans << '\n';
	}
}