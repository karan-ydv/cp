#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPrime(int n) {
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
	int n;	cin >> n;
	if(n == 1)	return cout << "1", 0;

	vector<int> v;
	v.push_back(1);
	for(int i = 2; i <= sqrt(n); i++) {
		if(isPrime(i))
		while(n % i == 0) {
			v.push_back(i);
			n /= i;
		}
	}
	if(isPrime(n))	v.push_back(n);
	
	int m = v.size();
	for(int i = 1; i < m; i++) {
		v[i] *= v[i - 1];
	}
	reverse(v.begin(), v.end());
	for(int x: v)	cout << x << ' ';
}