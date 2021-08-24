#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+5;
bitset<N> prime;
int ans[N];
void SieveOfEratosthenes() 
{ 
    prime.set();
    for (int p = 2; p * p <= N; p++) 
    { 
        if (prime[p]) 
        { 
            for (int i = p * p; i <= N; i += p) 
                prime[i] = 0; 
        }
    } 
    for(int i = 2; i < N; i++) {
        ans[i] = ans[i - 1] + prime[i];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    SieveOfEratosthenes();
    int t;  cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        int x = ans[n];
        if(n / 2 > 1)
        {
            x -= ans[n / 2] - 1;
        }
        cout << x << '\n';
    }
}