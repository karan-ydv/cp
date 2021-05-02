#include <bits/stdc++.h>
#define int long long
using namespace std;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	unordered_set<int, custom_hash> set;
	queue<int> q;
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		int x;	cin >> x;
		if(!set.count(x))
			set.insert(x), q.push(x);
		else
		{
			while(q.front() != x)
			{
				set.erase(q.front());
				q.pop();
			}
			q.pop();
			q.push(x);
		}
		ans = max(ans, (int)set.size());
	}
	cout << ans;
}