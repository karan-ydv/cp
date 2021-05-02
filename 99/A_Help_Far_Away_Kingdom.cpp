#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;	cin >> s;
	int i = s.find('.');
	if(s[i - 1] < '9')
	{
		if(s[i + 1] >= '5')
		{
			s[i - 1] += 1;
		}
		for(int j = 0; j < i; j++)
			cout << s[j];
	}
	else
	{
		cout << "GOTO Vasilisa.";
	}
}