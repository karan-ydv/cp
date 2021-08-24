#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int n, ans = 1e18;	cin >> n;
		// int A[n][n];
		// int B[n][n];
		int R[n], C[n];
		vector<vector<int>> A(n, vector<int>(n)), tmp;
		vector<vector<int>> B(n, vector<int>(n));
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

		int arr[2 * n];	iota(arr, arr + 2 * n, 0);
		do {
			tmp = B;
			int sum = 0;
			for(int i = 0; i < 2 * n; i++) {
				// cout << arr[i] << " \n"[i == 2 * n - 1];
				int x = 0;
				if(arr[i] < n) {
					int mx = 0;
					for(int j = 0; j < n; j++) {
						x += tmp[arr[i]][j];
						mx = max(mx, tmp[arr[i]][j]);
						tmp[arr[i]][j] = 0;
					}
					x -= mx;
				}
				else {
					int col = arr[i] - n;
					int mx = 0;
					for(int j = 0; j < n; j++) {
						x += tmp[j][col];
						mx = max(mx, tmp[j][col]);
						tmp[j][col] = 0;
					}
					x -= mx;
				}
				sum += x;
			}
			ans = min(ans, sum);
		} while ( std::next_permutation(arr, arr + 2 * n) );
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}