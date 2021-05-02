#include <bits/stdc++.h>
#define int long long
using namespace std;

bool same(string a, string b)
{

}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;	cin >> s;
	vector<string> v;
	sort(s.begin(), s.end());
	int ans = 0;
	do
	{
		bool unique = true;
		for(auto str: v)
		if(same(str, s))
		{
			unique = false;
			break;
		}
		ans += unique;
	} while(next_permutation(s.begin(), s.end()));
	cout << ans;
}