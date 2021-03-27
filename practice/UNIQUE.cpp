#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	string s;
	vector<node> v;
	node() {}
};

struct Trie
{
	map<node> v;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	cin.get();
	vector<pair<string, int>> v(n);
	for(int i = 0; i < n; i++)
	{
		v[i].second = i;
		getline(cin, v[i].first);
	}
	sort(v.begin(), v.end());
	vector<string> ans(n);
	for(int i = 0; i < n; i++)
	{
		auto [a, b] = v[i];

	}
}