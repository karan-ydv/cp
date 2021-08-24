#include <bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<int, int> dp;

int fun(int n)
{
    if(n == 1)  return 1;
    if(dp.count(n))
        return dp[n];
    
    for(int d: divisors(n))
        dp[n] = max(dp[n], d * fun(n / d));
    return dp[n];
}

int32_t main()
{
    int n, p;
    cin >> n >> p;
    int ans = 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
        {
            ans = max(ans, i * fun(n / i));
            ans = max(ans, (n / i) * fun(i));
        }
    }
    ans *= p;
    cout << ans;
}