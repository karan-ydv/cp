#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		string s; int n;
		cin >> n >> s;
		s = "!" + s;
		int Tpref[n + 2], Tsuff[n + 2];
		int Mpref[n + 2], Msuff[n + 2];
		Tpref[0] = Tsuff[n + 1] = 0;
		Mpref[0] = Msuff[n + 1] = 0;
		bool flag = true;
		for(int i = 1; i <= n; i++)
		{
			Tpref[i] = Tpref[i - 1] + (s[i] == 'T');
			Mpref[i] = Mpref[i - 1] + (s[i] == 'M');
			if(s[i] == 'M')
			flag &= (Tpref[i] >= Mpref[i]);
		}
		for(int i = n; i > 0; i--)
		{
			Tsuff[i] = Tsuff[i + 1] + (s[i] == 'T');
			Msuff[i] = Msuff[i + 1] + (s[i] == 'M');
			if(s[i] == 'M')
			flag &= (Tsuff[i] >= Msuff[i]);
		}
		flag &= (Tpref[n] == 2 * Mpref[n]);
		if(flag)	cout << "YES\n";
		else		cout << "NO\n";
	}
}