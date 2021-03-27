#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("digits.in", "r", stdin);
	string s;	cin >> s;
	int freq[10] = {0};
	for(auto c: s) {
		freq[c - '0']++;
	}

	string ans = "";
	for(auto c: s) {
		if(freq[c - '0'] == 1)
		{
			ans += c;
		}
		else if(freq[c - '0'] > 0)
		{
			char d;
			for(d = '0'; d < c; d++)
			{
				if(freq[d - '0'] > 0)
					break;
			}
			if(d == c)	
			{
				freq[c - '0'] = 1;
				ans += c;
			}
		}
		freq[c - '0'] --;
	}
	cout << ans;
}