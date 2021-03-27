#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;

struct Graph {
	typedef pair<pii, pii> item;
	vector<pii> u, v;	int n;
	vector<int> uf, us;
	Graph(vector<item> abc) {
		n = abc.size();
		u.resize(n);
		v.resize(n);
		uf.resize(n);
		for(int i = 0; i < n; i++) {
			u[i] = abc[i].first;
			// cout << u[i].first << ' ' << u[i].second << '\n';
			v[i] = abc[i].second;
			uf[i] = u[i].first;
		}
	}
	bool intersect(pii a, pii b) {
		// cout << a. first << ' ' << a.second << ", ";
		// cout << b. first << ' ' << b.second << ": ";
		// cout << !(a.first > b.second or a.second < b.first) << '\n'; 
		return !(a.second > b.first or a.first < b.second);
	}
	int binary(pii x) {
		int beg = 0, end = n - 1, ans;
		while(beg <= end)
		{
			int mid = beg + end >> 1;
			ans = mid;
			if(x.second > u[mid].first)
				beg = mid + 1;
			else
				end = mid - 1;
		}
		return ans;
	}
	int BFS(pii x, pii y)
	{
		queue<pair<pii, int>> q;
		unordered_set<int> visited;
		int i = binary(x);
		for(; i < n and x.second <= u[i].first; i++) {
			if(intersect(x, u[i])) {
				q.push({v[i], 1});
				visited.insert(i);
			}
		}
		while(!q.empty())
		{
			auto [f, d] = q.front();
			if(intersect(f, y))	return d;
			q.pop();			
			for(i = binary(f); i < n and f.second <= u[i].first; i++) {
				if(intersect(f, u[i]) and !visited.count(i)) {
					q.push({v[i], d + 1});
					visited.insert(i);
				}
			}
		}
		return -1;
	}
	void solve(int x, int y) {
		cout << BFS({x, x}, {y, y}) << '\n';
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, m, x, y;	cin >> n >> m >> x >> y;
		if(x == y)	{
			cout << "0\n";
			continue;
		}
		vector<pair<pii, pii>> A(m);
		for(auto &[a, b]: A) {
			
			cin >> a.second >> a.first;
			cin >> b.second >> b.first;
			// cin >> a.first >> a.second;
			// cin >> b.first >> b.second;
		}
		sort(A.begin(), A.end());
		Graph G(A);
		G.solve(x, y);
	}
}