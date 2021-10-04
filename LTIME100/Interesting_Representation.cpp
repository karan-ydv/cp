#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        if(n == 1)          cout << "3 2\n";
        else if(n % 2 == 0) cout << 2 * n << ' ' << n << '\n';
        else for(int p: primes) if(n % p)
        {
            cout << p * n << ' ' << (p - 1) * n << '\n';
            break;
        }
    }
}