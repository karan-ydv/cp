#include <bits/stdc++.h>
using namespace std;

list<int> L;
list<int>::iterator next(list<int>::iterator itr)
{
	++itr;
	if(itr == L.end())
		return L.begin();
	return itr;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	for(int i = 1; i <= n; i++)
		L.emplace_back(i);
	
	int c = 0;
	auto itr = L.begin();
	while(!L.empty())
	{
		auto nxt = next(itr);
		if(c & 1)
		{
			cout << *itr << ' ';
			L.erase(itr);
		}
		itr = nxt;
		c++;
	}
}