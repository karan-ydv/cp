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
		string s;	cin >> s;
		int n = s.length();
		int sum = 0, cnt = 0;
		for(char c: s)
		{
			sum += (c-'0');
			cnt += (c-'0') & 1;
		}
		if(sum & 1)
		{
			if(cnt > 1)	cout << "1\n";
			else		cout << "-1\n";
		}
		else
		{
			if(cnt)
				cout << "0\n";
			else
				cout << "-1\n";
		}
	}
}