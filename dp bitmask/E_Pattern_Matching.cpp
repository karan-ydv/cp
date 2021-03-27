#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;	cin >> n >> m >> k;
	string p[n], s[m];
	vector<pair<string, int>> A(n);
	vector<tuple<string, int, int>> B(n);
	for(int i = 1; i <= n; i++) {
		cin >> p[i- 1];
		A[i] = {p[i - 1], i};
	}
	for(int i = 0; i < m; i++) {
		cin >> s[i];
		B[i] = {s[i], i, 0};
	}
	for(auto &x: p)	cin >> x;
	for(auto &x: s)	cin >> x;
	int mt[m];
	for(auto &x: mt)	cin >> x;

	auto matches = [&](int si, int pi) {
		for(int i = 0; i < k; i++) {
			if(s[si][i] != p[pi][i] and p[pi][i] != '_')
				return false;
		}
		return true;
	};


}