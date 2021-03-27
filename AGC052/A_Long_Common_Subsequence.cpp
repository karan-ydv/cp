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
		n <<= 1;
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;

		string ans;
		bool x = (s1[n - 1] == '0' or s1[0] == '0');
		bool y = (s2[n - 1] == '0' or s2[0] == '0');
		bool z = (s3[n - 1] == '0' or s3[0] == '0');

		n >>= 1;
		if(x and y and z)
			ans = string(n, '1') + "0" + string(n, '1');
		else if (!x and !y and !z)
			ans = string(n, '0') + "1" + string(n, '0');
		else
			ans = string(n, '0') + string(n, '1') + "0";
		cout << ans << '\n';
	}
}