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
		int a[n + 2], p[n + 2], s[n + 2];
		int lneg[n + 2], rneg[n + 2];

		for(int i = 1; i <= n; i++) cin >> a[i];

		lneg[0] = p[0] = 0;
		for(int i = 1; i <= n; i++) {
			p[i] = a[i] - p[i - 1];
			lneg[i] = lneg[i - 1] + (p[i] < 0);
		}
		s[n + 1] = rneg[n + 1] = 0;
		for(int i = n; i > 0; i--) {
			s[i] = a[i] - s[i + 1];
			rneg[i] = rneg[i + 1] + (s[i] < 0);
		}
		
		bool flag = false;
		flag |= (p[n] == 0 and lneg[n] == 0);
		flag |= (s[1] == 0 and rneg[1] == 0);
		
		for(int i = 1; i < n; i++) {
			if(lneg[i] == 0 and rneg[i + 1] == 0)
			flag |= (p[i] == s[i + 1]);
			if(a[i + 1] >= p[i - 1] and a[i] >= s[i + 2])
			flag |= (a[i + 1] - p[i - 1] == a[i] - s[i + 2] and lneg[i - 1] == 0 and rneg[i + 2] == 0);
		}

		if(flag)	cout << "YES\n";
		else		cout << "NO\n";
	}
}