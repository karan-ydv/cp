#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int A[n];
	set<int> set;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		set.insert(i);
	}
	int q;	cin >> q;
	while(q--)
	{
		int x, k;	cin >> x >> k;
		x--;
		int ans = 0;
		auto itr = set.lower_bound(x);
		while(k and itr != set.end())
		{
			int i = *itr;
			if(A[i] > k)
			{
				ans += k * (i - x);
				A[i] -= k;
				k = 0;
				break;
			}
			else
			{
				auto prev = itr;
				++itr;
				ans += A[i] * (i - x);
				k -= A[i];
				A[i] = 0;
				set.erase(prev);
			}
		}
		cout << ans << '\n';
	}
}