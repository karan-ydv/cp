#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		set<int> s1, s2;
		for(int i = 1; i <= n; i++)	s1.insert(i), s2.insert(i);
		int q[n], mn[n], mx[n], x;
		for(int &x: q)	cin >> x;
		mx[0] = mn[0] = q[0];
		s1.erase(q[0]);
		s2.erase(q[0]);
		for(int i = 1; i < n; i++) {
			int x = q[i];
			if(x == q[i - 1]) {
				auto i1 = s1.begin();
				auto i2 = s2.upper_bound(x);
				if(i2 != s2.begin())	--i2;
				mn[i] = *i1;
				mx[i] = *i2;
				s1.erase(i1);
				s2.erase(i2);
			}
			else {
				mn[i] = mx[i] = x;
				s1.erase(x);
				s2.erase(x);
			}
		}
		for(int &x: mn)	cout << x << ' ';	cout << '\n';
		for(int &x: mx)	cout << x << ' ';	cout << '\n';
	}
}