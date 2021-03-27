#include <bits/stdc++.h>
#define int long long
using namespace std;

struct CITY {
	bool L, R;
	CITY() : L(0), R(0) {}
};
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		string s; int n;	cin >> n >> s;

		CITY city[2][n + 2];
		for(int i = 1; i <= n; i++) {
			if(s[i - 1] == 'L') {
				city[0][i + 1].L = true;
				city[1][i].R = true;
			}
			else {
				city[0][i].R = true;
				city[1][i + 1].L = true;
			}
		}

		int suff[2][n + 3], pref[2][n + 3];
		pref[0][0] = pref[1][0] = 0;
		for(int i = 1; i <= n + 1; i++) {
			pref[0][i] = 1 + pref[1][i - 1] * city[0][i].L;
			pref[1][i] = 1 + pref[0][i - 1] * city[1][i].L;
		}
		suff[0][n + 2] = suff[1][n + 2] = 0;
		for(int i = n + 1; i >= 1; i--) {
			suff[0][i] = 1 + suff[1][i + 1] * city[0][i].R;
			suff[1][i] = 1 + suff[0][i + 1] * city[1][i].R;
		}

		int ans[n + 3];
		for(int i = 1; i <= n + 1; i++) {
			ans[i] = pref[0][i] + suff[0][i] - 1;
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}