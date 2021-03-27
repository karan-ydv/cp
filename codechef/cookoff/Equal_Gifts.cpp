#include <bits/stdc++.h>
#define int long long
using namespace std;

bitset<100000000> b, c;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		b.reset();
		int n;	cin >> n;
		int a[n];
		unordered_map<int, int> mp;
		int i = 0;
		for(int &x: a)	cin >> x, b[x] =  1, mp[x] = i++;
		sort(a, a + n);
		for(i = 1; i < n; i++) {
			if(a[i] == a[i - 1])
				break;
		}
		string ans = string(n, 'N');
		if(i < n) {
			ans[i] = 'A';
			ans[i- 1] = 'B';
			cout << "YES\n";
			cout << ans << '\n';
			continue;
		}
		c[0] = 1;
		for(i = 0; i < n; i++) {
			c |= c << a[i];
			b[i] = 0;
			if((c & b).count()) {
				break;
			}
		}
		if(i == n)	cout << "NO\n";
		else
		{
			c &= b;
			int sum = c._Find_first();
			ans[mp[sum]] = 'B';
			
		}
	}
}