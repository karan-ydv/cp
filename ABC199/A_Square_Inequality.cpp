#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;	cin >> A >> B >> C;
	if(A * A + B * B < C * C)
		cout << "Yes";
	else
		cout << "No";
}