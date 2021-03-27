#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+5;
const int MAX = 1e6;
vector<int> primes(N);
bitset<MAX> prime;
void SieveOfEratosthenes(int n) 
{ 
	prime.set();
	for (int p = 2; p * p <= n; p++) 
	{ 
		if (prime[p]) 
		{ 
			for (int i = p * p; i <= n; i += p) 
				prime[i] = 0; 
		}
	} 
	int c = 0;
	for (int p = 2; p <= n and c < N; p++) 
		if (prime[p]) primes[c++] = p;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	SieveOfEratosthenes(1e6);
	cout << primes.size();
}