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
		string b;	cin >> b;
		string ans = "1";
		char prev = '1' + (b[0] - '0');
		for(int i = 1; i < n; i++)
		{
			// cout << "i = " << i << " " << ans << '\n';
			char p;
			if(b[i] == '0')
			{
				if(prev == '0')			ans += '1', p = '1';
				else if(prev == '1')	ans += '0', p = '0';
				else if(prev == '2')	ans += '1', p = '1';
			}
			else
			{
				if(prev == '0')			ans += '1', p = '2';
				else if(prev == '1')	ans += '1', p = '2';
				else if(prev == '2')	ans += '0', p = '1';
			}
			prev = p;
		}
		cout << ans << '\n';
	}
}