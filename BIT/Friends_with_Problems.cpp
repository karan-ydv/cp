#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int m = s[0].length();
	int ans = 1;
	for(int i = 0; i < m; i++)
	{
		set<char> st;
		for(int j = 0; j < n; j++)
		{
			st.insert(s[j][i]);
			if(st.size() > 1)	break;
		}
		if(st.size() == 1 and *st.begin() != '2')
			continue;
		ans *= 2;
		ans %= mod;
	}
	cout << ans;
}