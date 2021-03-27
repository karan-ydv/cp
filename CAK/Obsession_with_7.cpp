#include <bits/stdc++.h>
using namespace std;

int permute(string str)
{
    sort(str.begin(), str.end());
	int c = 0;
    do {
		int x = stoi(str);
		c += (x % 7 == 0);
    } while (next_permutation(str.begin(), str.end()));
	return c;
}
 

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		string s;	cin >> s;
		int ans = permute(s);
		cout << ans << '\n';
	}
}