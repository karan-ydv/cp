#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, T;	cin >> n >> T;
	int sum = 0, ans = 0;
	queue<pii> q;
	for(int i = 0; i < n; i++) 
	{
		int x;	cin >> x;
		q.push({x, i});
		sum += x;
	}
	while(1)
	{
		if(sum >= T)
		{
			ans += sum / T;
			sum %= T;
		}
		auto [f, idx] = q.front();	q.pop();
		if(f > T)
		{
			if(idx == 0)	break;
			sum -= f;
		}
		else
		{
			T -= f;
			ans ++;
			q.push({f, idx});
		}
	}
	cout << ans;
}