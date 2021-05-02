#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;	cin >> a >> b;
	vector<int> v1, v2;
	int i = 1;
	while(a > 0 and b > 0)
		v1.emplace_back(i), v2.emplace_back(-i), i++, a--, b--;
	while(a > 0)
		v1.emplace_back(i), v2[v2.size() - 1] -= i, i++, a--;
	while(b > 0)
		v2.emplace_back(-i), v1[v1.size() - 1] += i, i++, b--;
	
	for(int x: v1)	cout << x << ' ';
	for(int x: v2)	cout << x << ' ';
}