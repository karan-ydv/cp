// Dear whoever added unordered map hack case, fuck you!!
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
		map<int, int> mp1;
		int a[n];	for(int &x: a)	cin >> x, mp1[x]++;
		vector<int> v;
		for(auto [a, b]: mp1) {
			v.push_back(b);
		}
		int m = v.size();
		sort(v.begin(), v.end());
		int suff[m + 1], pref[m + 1];
		suff[m] = 0;
		pref[0] = 0;
		int c = v[0];
		for(int i = 1; i < m; i++) {
			pref[i] = pref[i - 1];
			if(v[i] != v[i - 1]) {
				pref[i] += c;
				c = 0;
			}
			c += v[i];
		}
		for(int i = m - 1; i >= 0; i--) {
			suff[i] = suff[i + 1] + v[i];
		}
		
		int ans = n;
		for(int i = 0; i < m; i++) {
			ans = min(ans, pref[i] + suff[i] - v[i] * (m - i));
		}
		cout << ans << '\n';
	}
}