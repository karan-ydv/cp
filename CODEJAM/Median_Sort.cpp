#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, q;	cin >> t >> n >> q;
	for(int _ = 1; _ <= t; _ ++) {
		vector<int> v = {1, 2, 3};
		cout << "1 2 3" << endl;
		int x;	cin >> x;
		if(x == 1)	swap(v[0], v[1]);
		if(x == 3)	swap(v[2], v[1]);
		
		auto mexfind = [&](){
			for(int i = 3; i <= n; i++) {
				if(find(v.begin(), v.end(), i) == v.end())
					return i;
			}
			return 0ll;
		};

		while(v.size() != n)
		{
			int mex = mexfind();
			int m = v.size();
			for(int i = 0; i < m - 1; i++)
			{
				cout << v[i] << ' ' << v[i + 1] << ' ' << mex << endl;
				cin >> x;
				if(x == v[i]){
					v.insert(v.begin() + i, mex);
					break;
				}
				else if(x == mex) {
					v.insert(v.begin() + i + 1, mex);
					break;
				}
			}
			if(v.size() == m)	v.emplace_back(mex);
		}
		for(int x: v)	cout << x << ' ';	cout << endl;
		cin >> x;
	}
}