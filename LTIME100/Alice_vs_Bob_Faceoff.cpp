#include <bits/stdc++.h>
#define int int64_t
using namespace std;

map<int, bool> dp;

bool fun(int n)
{
    if(n == 1)  return true;
    if(dp.count(n)) return dp[n];
    
    if(n & 1)   return dp[n] = !fun(n - 1);
    if(n % 4 == 0)  return dp[n] = 1;
    return dp[n] = !fun(n / 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {   
        int n;	cin >> n;
        if(fun(n))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}