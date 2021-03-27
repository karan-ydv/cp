#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	int a[n];	for(int &x: a)	cin >> x;
	multiset<int> set1;
	set<int> set2;
	for(int i = 0; i <= 1.5e6 + 1; i++)
		set2.insert(i);
	for(int j = 0; j < m; j++) {
		set1.insert(a[j]);
		auto x = set2.find(a[j]);
		if(x != set2.end()) {
			set2.erase(x);
		}
	}
	int ans = *set2.begin();
	for(int i = m; i < n; i++) {
		set1.insert(a[i]);
		auto x = set2.find(a[i]);
		if(x != set2.end()) {
			set2.erase(x);
		}
		x = set1.find(a[i - m]);
		set1.erase(x);
		x = set1.find(a[i - m]);
		if(x == set1.end()) {
			set2.insert(a[i - m]);
		}
		ans = min(ans, *set2.begin());
	}
	cout << ans;
}