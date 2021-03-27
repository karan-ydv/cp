#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, W;	cin >> A >> B >> W;
	W *= 1000;

	if(W < A)	return cout << "UNSATISFIABLE", 0;
	if(A == B)
	{
		if(W % A == 0) {
			cout << W / A << ' ' << W / A;
		}
		else cout << "UNSATISFIABLE", 0;
		return 0;
	}

	int mn = 0, mx = 0;
	auto possible = [&](int n) {
		double x = W * 1.0 / n;
		return x >= A and x <= B;
	};
	int beg = 1, end = 1e7;
	for(int i = 1; i <= 5e6; i++) {
		if(possible(i)) {
			mn = i;
			break;
		}
	}
	for(int i = 5e6; i > 0; i--) {
		if(possible(i)) {
			mx = i;
			break;
		}
	}
	if(mn and mx)
	cout << mn << ' ' << mx;
	else
	cout << "UNSATISFIABLE";
}