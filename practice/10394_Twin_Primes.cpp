#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e7+5;
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
}

const int N = 1e5+1;
pair<int, int> ans[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    SieveOfEratosthenes(MAX - 2);
    for(int i = 3, c = 0; i < MAX and c < N; i++) {
        if(prime[i] and prime[i + 2])  ans[++c] = {i, i + 2};
    }
    int x;
    while(cin >> x)
    {
        cout << "(" << ans[x].first << ", " << ans[x].second << ")\n";
    }
}