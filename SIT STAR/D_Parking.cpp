#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;	int n, a, b;
	cin >> n >> a >> b >> s;
	s += '1';
	vector<int> A, B;
	int c = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] ==  '0') {
			if(A.size() < a)
			{
				if(s[i + 1] == '0') {
					A.emplace_back(i + 1);
					i++;
				}
				else if(B.size() < b)
					B.emplace_back(i + 1);
			}
			else if(B.size() < b)
			{
				B.emplace_back(i + 1);
			}
		}
	}
	if(A.size() == a and B.size() == b)	
	{
		cout << "YES\n";
		for(int i: A)	cout << i << ' ' << i + 1 << '\n';
		for(int i: B)	cout << i << '\n';
	}
	else cout << "NO\n";
}