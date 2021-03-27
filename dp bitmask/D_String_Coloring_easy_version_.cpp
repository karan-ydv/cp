#include <bits/stdc++.h>
#define int long long
using namespace std;

#define f first
#define s second

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	string s; cin >> n >> s;
	vector< pair<char, int> > v;
	for(int i = 0; i < n; i++)
	{
		v.emplace_back(s[i], i);
	}
	string color(n, 'x');
	color[0] = '0';
	bool flag = true;
	for(int i = 1; i < n; i++) {
		color[v[i].s] = color[v[i - 1].s];
		if(v[i].f < v[i - 1].f)
			color[v[i].s] ^= '0' ^ '1';
		// cout << color << '\n';
		for(int j = i; j > 0 and v[j].f < v[j - 1].f; j--) {
			if(color[v[j - 1].s] == color[v[j].s]) {
				flag = false;
				goto end;
			}
			swap(v[j], v[j - 1]);
			// cout << color << '\n';
		}
	}
	end:
	if(flag)	cout << "YES\n" << color;
	else		cout << "NO\n";
}