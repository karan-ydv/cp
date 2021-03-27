#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		stack<pair<int, int>> h;
		int ans = 1;
		auto slope = [](pii a, pii b) {
			double m = a.first - b.first;
			m /= b.second - a.second;
			return m;
		};
		for(int R = 0; R < n; R++) {
			int x;	cin >> x;
			pii p = {x, R};
			if(h.size())
			{
				auto p0 = h.top();
				h.pop();
				while(h.size())
				{
					auto p1 = h.top();
					if(slope(p1, p) >= slope(p0, p)) {
						h.pop();
						p0 = p1;
					}
					else	break;
				}
				ans = max(ans, R - p0.second);
				h.push(p0);
			}
			h.push(p);
		}
		cout << ans << '\n';
	}
}