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
		int n;	cin >> n;
		bool flag = false;
		for(int i = 1; i * i * i < n; i++) {
			int j = n - i * i * i;
			int k = pow(j, 1.0/3);
			for(int a = k - 5; a < k + 5; a++) if(a > 0){
				if(a * a * a == j) {
					flag = 1;
					goto end;
				}
			}
		}
		end:
		if(flag)	cout << "YES\n";
		else		cout << "NO\n";
	}
}