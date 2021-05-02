#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 505;
int A[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < N; i++)
		A[i][0] = -1, A[0][i] = -1;
	int n; cin >> n;
	for(int k = 1; k <= n; k++)
	{
		int x;	cin >> x;
		int i = k, j = k, c = x - 1;
		A[i][j] = x;

		if(A[i][j - 1] == 0)	j--;
		else i++;

		if(c > 0)	A[i][j] = x;
		while(--c > 0)
		{
			if(A[i - 1][j] == 0)		A[--i][j] = x;
			else if(A[i][j - 1] == 0)	A[i][--j] = x;
			else						A[++i][j] = x;
		}
	}
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= i; j++)
		cout << A[i][j] << " \n"[j == i];
}