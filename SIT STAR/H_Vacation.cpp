#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	vector<int> one, two;
	for(int i = 0; i < n; i++) {
		int c, t;
		cin >> c >> t;
		if(t == 1)	one.emplace_back(c);
		else		two.emplace_back(c);
	}
	one.emplace_back(1 << 30);
	two.emplace_back(1 << 30);

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	tuple<int, int, int> dp[n];
	dp[0] = {min(one[0], two[0]), ,}
}