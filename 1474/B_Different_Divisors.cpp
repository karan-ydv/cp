#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4;
int primes[N];
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
	int c = 0;
    for (int p=2; p<=n and c < N; p++) 
       if (prime[p]) primes[c++] = p;
	// cout << primes[c - 1] << ' ';
	// cout << c << '\n';
} 

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	SieveOfEratosthenes(100000);
	int t;	cin >> t;
	while(t--)
	{
		int d;	cin >> d;
		auto p1 = lower_bound(primes, primes + N, d + 1);
		auto p2 = lower_bound(primes, primes + N, *p1 + d);
		// cout << p2 - primes << ' ';
		int a = *p1;
		int b = *p2;
		int x = a * b;
		// cout << a << ' ' << b  << '\n';
		cout << x << '\n';
	}
}