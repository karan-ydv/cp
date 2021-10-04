#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve()
{
    int a, b;   cin >> a >> b;
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            if(b % i != 0)  return false;
            while(a % i == 0)
                a /= i;
        }
    }
    return b % a == 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve() ? coue << "YES\n" : cout << "NO\n";
    }
}