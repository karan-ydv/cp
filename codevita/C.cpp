#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; int n;
	cin >> n >> s;
	s += '!';
	vector<string> v;
	bool flag = true;
	int last = -1;
	for(int i = 0; i < n; i++)
	{
		set<char> st;
		string t = "";
		int j;
		for(j = i; j < n; j++)
		{
			if(st.count(s[j]))
			{
				// if improper then no
				if(j > last)
				{
					if(s[j] == s[i])
					{
						if(v.empty())
						{
							v.emplace_back(t);
							last = j;
						}
					}
					else
					{
						v.emplace_back(t);
						last = j;
					}
				}
				break;
			}
			else
			{
				t += s[j];
				st.insert(s[j]);
			}
		}
		if(j == n)
		{
			if(j > last)
			{
				v.emplace_back(t);
				last = n;
			}
		}
	}
	sort(v.begin(), v.end());
	for(auto &x: v)	cout << x << ' ';
}