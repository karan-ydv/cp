#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> v, a;
	v.emplace_back("-1");
    a.emplace_back("-1");
	for(int year = 1; year < 10000; year++)
	{
		string yyyy = to_string(year);
		yyyy = string(4 - yyyy.length(), '0') + yyyy;
		for(int month = 1; month < 13; month++)
		{
			string mm = to_string(month);
			if(month < 10) mm = "0" + mm;
			for(int day = 1; day < 31; day++)
			{
				string dd = to_string(day);
				if(day < 10) dd = "0" + dd;
				string s = dd + mm + yyyy;
				bool palindrome = true;
				for(int i = 0; palindrome and i < 4; i++)
				if(s[i] != s[7 - i]) palindrome = false;
				if(palindrome)
                {
                    v.emplace_back(yyyy + mm + dd);
                    a.emplace_back(s);
                }
			}
		}
	}
	int _;	cin >> _;
	while(_ --> 0)
	{
		string s;	cin >> s;
        string x = s.substr(4, 4) + s.substr(2, 2) + s.substr(0, 2);
		int i = lower_bound(v.begin() + 1, v.end(), x) - v.begin();
		cout << a[i - 1] << '\n';
	}
}