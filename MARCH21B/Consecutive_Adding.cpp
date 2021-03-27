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
		int n, m, x;	cin >> n >> m >> x;
		int A[n + 1][m + 1], D[n + 1][m + 1];

		for(int i = 0; i <= n; i++) A[i][0] = D[i][0] = 0;
		for(int i = 0; i <= m; i++)	A[0][i] = D[0][i] = 0;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> A[i][j];
			}
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				int v;	cin >> v;
				A[i][j] = v - A[i][j];
				D[i][j] = A[i][j] - A[i][j - 1];
			}
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j + x <= m + 1; j++) {
				int c = D[i][j];
				D[i][j] -= c;
				if(j + x <= m)
				D[i][j + x] += c;
			}
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				D[i][j] += D[i][j - 1];
				A[i][j] = D[i][j];
			}
		}

		for(int i = m - x + 2; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				D[j][i] = A[j][i] - A[j - 1][i];
			}
		}

		for(int i = m - x + 2; i <= m; i++) {
			for(int j = 1; j <= n - x + 1; j++) {
				int c = D[j][i];
				D[j][i] -= c;
				if(j + x <= n)
				D[j + x][i] += c;
			}
		}
		
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) if(D[i][j] != 0) {
				flag = false;
				goto end;
			}
		}

		end:
		if(flag)	cout << "Yes\n";
		else		cout << "No\n";
	}
}