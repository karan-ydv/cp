#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin  >> t;
	int T = t;
	while(t--)
	{
		cout << "Case " << T - t << ":\n";
		int n;	cin >> n;
		vector<string> v(n);
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
			reverse(v[i].begin(), v[i].end());
		}
		sort(v.begin(), v.end());
		for(auto s: v)
		{
			reverse(s.begin(), s.end());
			cout << s << '\n';
		}
	}
}