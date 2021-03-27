#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int dp[100][1000001];
int c[100];
int fun(int n, int x)
{
    
    if(x == 0)      return 1;
    if(n < 0 or x < 0)  return 0;
    if(dp[n][x])    return dp[n][x];
    dp[n][x] = fun(n - 1, x) + fun(n, x - c[n]);
    if(dp[n][x] >= mod) dp[n][x] -= mod;
    return dp[n][x];
}
int main()
{
    int n, x;   cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    cout << fun(n - 1, x);
}