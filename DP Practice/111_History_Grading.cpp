#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	while(n)
	{
		int A[n + 1];
		pair<int, int> a[n + 1];
		for(int i = 1; i <= n; i++) {
			int x;	cin >> x;
			a[i] = {x, i};
		}
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= n; i++)
			A[a[i].second] = i;
		while(1)
		{
			if(cin.peek() == EOF) {
				n = 0; break;
			}
			pair<int, int> b[n + 1];
			cin >> b[1].first;
			b[1].second = 1;
			if(cin.peek() == '\n') {
				n = b[1].first; break;
			}
			for(int i = 2; i <= n; i++)
			{
				int x;	cin >> x;
				b[i] = {x, i};
			}
			sort(b + 1, b + 1 + n);
			set<int> set;
			for(int i = 1; i <= n; i++) {
				auto itr = set.lower_bound(A[b[i].second]);
				if(itr != set.end())
					set.erase(itr);
				set.insert(A[b[i].second]);
			}
			cout << set.size() << '\n';
		}
	}
}