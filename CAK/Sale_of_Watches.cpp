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
		int rating[8], price[8];
		for(int i = 1; i <= 7; i++)	cin >> price[i];
		for(int i = 1; i <= 7; i++) cin >> rating[i];
		
		int c = 0, lastprice = 2e9, lastrating = -2e9;
		for(int i = 1; i <= 7; i++) {
			if(price[i] >= lastprice)	continue;
			if(rating[i] <= lastrating)	continue;
			if(i & 1) {
				if(!(rating[i] & 1))	continue;
				if(!(price[i] & 1))		continue;
				c++;
				lastprice = price[i];
				lastrating = rating[i];
			}
			else {
				if((rating[i] & 1))		continue;
				if((price[i] & 1))		continue;
				c++;
				lastprice = price[i];
				lastrating = rating[i];

			}
		}
		cout << c << '\n';
	}
}