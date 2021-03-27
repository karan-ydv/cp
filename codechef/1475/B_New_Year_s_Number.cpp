#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
bitset<N> year, b;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	year[2021] = 1;
	for(int i = 2020; i < N; i+= 2020) {
		year[i] = 1;
	}
	for(int j = 2021; j < N; j += 2021) {
		year |= (year << j);
	}
	while(t--)
	{
		int n;	cin >> n;
		if(year[n])	cout << "YES\n";
		else		cout << "NO\n";
	}
}