#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+5;
vector<int> primes;
bitset<N> prime;

void SieveOfEratosthenes() 
{ 
    prime.set();
    for (int p = 2; p * p < N; p++) if (prime[p]) 
        for (int i = p * p; i < N; i += p) prime[i] = 0; 

    for (int p = 2; p < N; p++) 
        if (prime[p]) primes.emplace_back(p);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    SieveOfEratosthenes();
    int t;	cin >> t;
    while(t--)
    {
        int x, y;   cin >> x >> y;
        int ny = upper_bound(primes.begin(), primes.end(), y) - primes.begin();
        int nx = upper_bound(primes.begin(), primes.end(), x + 1) - primes.begin();
        int ans = (y - x) - (ny - nx);
        cout << ans << '\n';
    }
}