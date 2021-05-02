#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n;
const int N = 1e4+5;
int dp[N], A[N], B[N];

int fun(int H)
{
	if(H <= 0)		return 0;
	if(dp[H])	return dp[H];
	int ret = 1 << 30;
	for(int i = 0; i < n; i++)
		ret = min(ret, fun(H - A[i]) + B[i]);
	return dp[H] = ret;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H;		cin >> H >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i] >> B[i];
	cout << fun(H);
}