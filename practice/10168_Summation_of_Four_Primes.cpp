#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 69;
bitset<MAX> prime;
vector<int> primes;
void SieveOfEratosthenes(int n)
{
    prime.set();
    for (int p = 2; p * p <= n; p++)
        if (prime[p])
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
    primes.emplace_back(2);
    for(int i = 3; i <= n; i += 2) {
        if(prime[i]) primes.emplace_back(i);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    SieveOfEratosthenes(MAX - 2);
    int x;
    while (cin >> x)
    {
        if (x < 8) cout << "Impossible.\n";
        else
        {
            cout << "2 " << (2 | (x & 1)) << " ";
            x -= 4 | (x & 1);
            for(int p: primes) if(prime[x - p]) {
                cout << p << ' ' << x - p << '\n';
                break;
            }
        }
    }
}