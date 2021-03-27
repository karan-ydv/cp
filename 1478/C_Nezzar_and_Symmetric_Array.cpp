#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		n <<= 1;
		int d[n];	for(int &x: d)	cin >> x;
		sort(d, d + n);
		vector<int> v;
		bool flag = true;
		for(int i = 1; i < n; i += 2)
		{
			if(d[i] != d[i - 1])
			{
				flag = false;
				break;
			}
			v.emplace_back(d[i]);
		}
		v.resize(unique(v.begin(), v.end()) - v.begin());
		if(v.size() != (n >> 1))
		{
			cout << "NO\n";
			continue;
		}
		int sum = 0;
		unordered_set<int> st;
		for(int i = n; i >= 0; i -= 2)
		{
			int x = d[i] - sum;
			if(x % i != 0)
			{
				flag = false;
				break;
			}
			x /= i;
			st.insert(x);
			
		}
		flag = false
	}
}