#include <bits/stdc++.h>
#include "bitset2.hpp"
#define int int64_t
using namespace std;
using namespace std::chrono;
using namespace Bitset2;

const int N = 1.1e9;
vect
constexpr void SieveOfEratosthenes() 
{
	for (int32_t p = 2; p * p <= N; p++) 
	{ 
		if (prime[p]) 
		{ 
			for (int32_t i = p * p; i <= N; i += p) 
				prime[i] = 0; 
		}
	}
}

int32_t main()
{
	auto start = high_resolution_clock::now();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	SieveOfEratosthenes();
	int t;	cin >> t;
	for(int _ = 1; _ <= t; _ ++)
	{
		int n;	cin >> n;
		int s = sqrt(n) + 1;
		int p = s, q = s + 1;
		while(!prime[p])	p--;
		while(!prime[q])	q++;
		if(p * q > n)
		{
			q = p;
			p -= 1;
			while(1)
			{
				if(prime[p])
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
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cerr << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}