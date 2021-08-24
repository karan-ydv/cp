#include <bits/stdc++.h>
using namespace std;

const int MAX = 3.2e4;
vector<int> primes;
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
    for (int p = 2; p <= n; p++) 
        if (prime[p]) primes.emplace_back(p);
}

int sum(int n)
{
    int s = 0;
    for(int p: primes)
    {
        while(n % p == 0)
        {
            s ++;
            n /= p;
        }
        if(n == 1) break;
    }
    s += n > 1;
    return s;
}

void solve(int a, int b, int k)
{
    if(b < a) swap(a, b);
    if(a == 1)
    {
        if(sum(b) < k)  cout << "NO\n";
        else            cout << "YES\n";
        return;
    }

    int x = sum(a), y = sum(b);
    // cerr << x << ' ' << y << '\n';
    if(k > x + y)  cout << "NO\n";
    else if(k == 1)
    {
        if(b % a == 0 and b != a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else    cout << "YES\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    primes.reserve(5000);
    SieveOfEratosthenes(32000);

    int t;	cin >> t;
    while(t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        solve(a, b, k);
    }
}