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
		string s;
		int n, k;	cin >> n >> k >> s;
		vector<int> v;
		for(int i = 0; i < n; i++) {
			if(s[i] == '*')	v.emplace_back(i);
		}
		int ans;
		if(v.size() < 3) {
			ans = v.size();
		}
		else
		{
			ans = 2;
			int x = v[0] + k;
			int b = v.size();
			for(int i = 0; i < b - 1; i++) {
				if(v[i + 1] > x) {
					ans ++;
					x = v[i] + k;
				}
			}
		}
		cout << ans << '\n';
	}
}