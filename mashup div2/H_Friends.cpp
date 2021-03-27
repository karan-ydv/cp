#include <bits/stdc++.h>
#define int long long
using namespace std;

bool f[6][6];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;	cin >> m;
	while(m--)
	{
		int a, b;	cin >> a >> b;
		f[a][b] = 1;
		f[b][a] = 1;
	}

	for(int i = 1; i < 1 << 5; i++) {
		bitset<5> b(i);
		if(b.count() != 3)	continue;
		vector<int> v;
		for(int i = 0; i < 5; i++) {
			if(b[i])	v.push_back(i + 1);
		}
		int x = v[0], y = v[1], z = v[2];
		if(f[x][y] and f[x][z] and f[y][z])
			return cout << "WIN", 0;
		if(!f[x][y] and !f[x][z] and !f[y][z])
			return cout << "WIN", 0;
	}
	cout << "FAIL";
}