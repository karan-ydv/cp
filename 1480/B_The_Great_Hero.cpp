#include <bits/stdc++.h>
#define int long long
using namespace std;

struct monster {
	int a, b;
	monster() {}
};


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int A, B, n;	cin >> A >> B >> n;

		monster v[n];
		for(auto &x: v)	cin >> x.a;
		for(auto &x: v)	cin >> x.b;

		vector<int> a;
		int i;
		for(i = 0; i < n; i++)
		{
			if(B <= 0)	break;
			int x = v[i].b / A;
			B -= v[i].a * x;
			v[i].b -= A * x;

			if(v[i].b != 0)
				a.emplace_back(v[i].a);
		}
		if(i < n)
		{
			cout << "NO\n";
			continue;
		}
		sort(a.begin(), a.end());
		bool flag = true;
		for(auto x: a)
		{
			if(B <= 0)
			{
				flag = false;
				break;
			}
			B -= x;
		}
		if(flag)	cout << "YES\n";
		else		cout << "NO\n";
	}
}