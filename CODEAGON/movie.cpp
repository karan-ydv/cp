#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int maxEvents(vector<int> arrival, vector<int> duration) {
    int n = arrival.size();
    pair<int, int> p[n];
    for(int i = 0; i < n; i++)
        p[i] = {arrival[i] + duration[i], arrival[i]};
    sort(p, p + n);
    int ans = 0, t = 0;
	for(int i = 0; i < n; i++)
	if(p[i].second >= t)
	{
		ans++;
		t = p[i].first;
	}
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<int> a(n), d(n);
    for(int &x: a)  cin >> x;
    for(int &x: d)  cin >> x;
    cout << maxEvents(a, d);
}