#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int dp[31][31];

string solve(int a, int b, int k)
{
    // cerr << a  << ' ' << b << ' ' << k << ": " << dp[a - 1][b] << endl;
    if(k == 1)  return string(a, 'a') + string(b, 'b');
    if(dp[a - 1][b] == k)   return "a" + string(b, 'b') + string(a - 1, 'a');
    if(dp[a - 1][b] > k)    return "a" + solve(a - 1, b, k);
    return "b" + solve(a, b - 1, k - dp[a - 1][b]);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, k;    cin >> a >> b >> k;
    for(int i = 1; i <= 30; i++)
        dp[i][0] = dp[0][i] = 1;
    
    for(int i = 1; i <= 30; i++)
        for(int j = 1; j <= 30; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    
    cout << solve(a, b, k);
}