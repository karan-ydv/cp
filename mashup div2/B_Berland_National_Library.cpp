#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 1;
bool A[N];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	char ch[n];	int X[n];
	for(int i = 0; i < n; i++) {
		cin >> ch[i] >> X[i];
	}
	int c = 0;
	for(int i = 0; i < n; i++) {
		if(ch[i] == '+')	A[X[i]] = 1;
		if(ch[i] == '-')
		{
			if(A[X[i]])	A[X[i]] = 0;
			else c++;
		}
	}
	int ans = c;
	for(int i = 0; i < n; i++) {
		if(ch[i] == '+')	c++;
		else				c--;
		ans = max(ans, c);
	}
	cout << ans;
}