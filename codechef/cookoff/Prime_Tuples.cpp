#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 9;
int dp[N];
vector<int> primes;
bitset<N> prime, c;

void SieveOfEratosthenes(int n)
{
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])	primes.push_back(p);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	prime.set();
	SieveOfEratosthenes(1e6);
	
	for(int p: primes) {
		if(prime[p + 2]) {
			c[p + 2] = true;
		}
	}
	int dp[N];
	for(int i = 5; i < N; i++) {
		dp[i] = dp[i - 1] + c[i];
	}
	int t;	cin >> t;
	while(t--)
	{
		int n;	cin >> n;
		cout << dp[n] << '\n';
	}
}