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
		vector<int> even, odd;
		for(int i = 0; i < n; i++)
		{
			int x;	cin >> x;
			if(x & 1)	odd.emplace_back(x);
			else		even.emplace_back(x);
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		int score[2] = {0}, f = 0;
		while(!odd.empty() or !even.empty())
		{
			if(odd.empty()) {
				if(f == 0)	score[f] += even.back();
				even.pop_back();
			}
			else if(even.empty()) {
				if(f == 1)	score[f] += odd.back();
				odd.pop_back();
			}
			else if(odd.back() > even.back()) {
				if(f == 1)	score[f] += odd.back();
				odd.pop_back();
			}
			else {
				if(f == 0)	score[f] += even.back();
				even.pop_back();
			}
			f = 1 - f;
		}
		if(score[0] > score[1])			cout << "Alice\n";
		else if(score[1] > score[0])	cout << "Bob\n";
		else							cout << "Tie\n";
	}
}