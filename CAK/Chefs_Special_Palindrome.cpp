#include <bits/stdc++.h>
#define int long long
using namespace std;

bool pal(string s) {
	string t = "";
	for(auto c: s) {
		if(isdigit(c))
			return false;
		if(isalpha(c)) {
			t += tolower(c);
		}
	}
	string u = t;
	reverse(u.begin(), u.end());
	return u == t;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	cin.get();
	while(t--)
	{
		string s; getline(cin, s);
		if(pal(s))	cout << "YES\n";
		else		cout << "NO\n";
	}
}