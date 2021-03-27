#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;	cin >> s;
	int ans = 0;
	for(char x: {'A', 'C', 'G', 'T'})
	{
		int a = 0;
		for(char c: s) {
			if(c == x) {
				a ++;
				ans = max(ans, a);
			}
			else {
				a = 0;
			}
		}
	}
	cout << ans;
}