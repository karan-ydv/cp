#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n], b[n];
	unordered_map<int, int> mp1, mp2;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		mp1[a[i]]++;
		mp2[a[i]]++;
	}
	
}