#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool prime(int n)
{
	if(n == 1)	return false;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0)	return false;
	}
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++)
	{
		int n;	cin >> n;
		int s = sqrt(n) + 1;
		int p = s, q = s + 1;
		while(!prime(p))	p--;
		while(!prime(q))	q++;
		if(p * q > n)
		{
			q = p;
			p -= 1;
			while(1)
			{
				if(prime(p))
				{
					if(p * q <= n)
						break;
					q = p;
				}
				p--;
			}
		}
		int ans = p * q;
		cout << "Case #" << _ << ": " << ans << '\n';
	}
}