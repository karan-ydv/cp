#include <bits/stdc++.h>
#define int long long
using namespace std;

bool lucky(string s) {
	for(char c: s) {
		// cout << c << ' ';
		if(c != '4' and c != '7')
			return false;
	}
	return true;
}
bool nearlylucky(string &s) {
	int d = 0, sum = 0;
	for(char c: s) {
		d += (c == '4' or c == '7');
		sum += (c - '0');
	}
	return lucky(to_string(d)) and lucky(to_string(sum));
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < n; i++) {
		string s;	cin >> s;
		// cout << s << '\n';
		bool luck, near = false;
		luck = lucky(s);
		if(!luck)
		near = nearlylucky(s);
		a += luck;
		b += near;
		c += (!luck and !near);
	}
	// cout << lucky("77") << '\n';
	cout << a << ' ' << b << ' ' << c;
}