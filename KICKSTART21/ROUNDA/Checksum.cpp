#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int n, ans = 0;	cin >> n;
		int A[n][n], B[n][n], R[n], C[n];
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> B[i][j];
		
		for(int &x: R)	cin >> x;
		for(int &x: C)	cin >> x;

		int nrow[n] = {0}, ncol[n] = {0}, x = 0;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			x += (A[i][j] == -1);
			nrow[i] += (A[i][j] == -1);
			ncol[i] += (A[j][i] == -1);
		}

		int brow[n] = {0}, bcol[n] = {0};
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			brow[i] += B[i][j];
			ncol[i] += B[j][i];
		}

		while(x)
		{
			int delta = 0;
			for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			if(A[i][j] == -1)
			{
				if(nrow[i] == 1 or ncol[j] == 1)
				{
					nrow[i]--, ncol[j]--;
					brow[i] -= B[i][j];
					bcol[j] -= B[i][j];
					A[i][j] = 2;
					x--;
					delta++;
				}
			}
			if(delta == 0)
			{
				int mnr = 1e18, ri;
				for(int i = 0; i < n; i++) if(nrow[i]) {
					int sum = brow[i] - *max_element(A[i], A[i] + n);
					if(sum < mnr)	
				}
			}
		}
		for(int i = 0; i < n; i++)
			cout << nrow[i] << " " << ncol[i] << '\n';
		cout << "Case #" << _ << ": " << ans << '\n';
		
	}
}