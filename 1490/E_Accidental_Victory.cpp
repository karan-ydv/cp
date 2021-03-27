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
		pair<int, int> a[n + 1];
		for(int i = 1; i <= n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a + 1, a + n + 1);
		int pref[n + 2];
		bool suff[n + 2];
		pref[0] = 0;
		for(int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + a[i].first;
		}
		suff[n] = true;
		vector<int> v;
		v.push_back(a[n].second);
		for(int i = n - 1; i > 0; i--) {
			// cout << pref[i] << ' ' << a[i + 1].first << '\n';
			suff[i] = suff[i + 1] & (pref[i] >= a[i +  1].first);
			if(suff[i]) {
				v.push_back(a[i].second);
			}
		}
		sort(v.begin(), v.end());
		cout << v.size() << '\n';
		for(auto x: v)	cout << x << ' ';	cout << '\n';
	}
}