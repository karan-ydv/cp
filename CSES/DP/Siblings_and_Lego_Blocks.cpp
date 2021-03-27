#include <bits/stdc++.h>
using namespace std;


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		list<string> L;
		for(int i = 0; i < n; i++)
		{
			string s;	int x;
			cin >> s >> x;
			auto itr = L.begin();
			while(--x)	itr++;
			L.insert(itr, s);
			// cout << "List: "; for(auto str: L)	cout << str << " "; cout << "\n";
		}
		unordered_set<string> s;
		int m;	cin >> m;
		while(m--)
		{
			string str;	cin >> str;
			s.insert(str);
		}
		int cnt = 0;
		for(auto str: L)
		{
			if(!s.count(str))
				cout << str << '\n', cnt++;
		}
		if(cnt == 0)	cout << "-1\n";
	}
}