#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 24;
const int X = (1 << N) - 1;
int dp[1 << N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 0; i < n; i++) {
        string s;   cin >> s;
        int x = 0;
        for(char c: s) x |= 1 << (c - 'a');
        dp[x] = 1;
    }
    
    for(int bit = 1; bit <= X; bit <<= 1)
    for(int mask = 1; mask <= X; mask++)
    if(mask & bit)
        dp[mask] += dp[mask ^ bit];

    int ans = 0;
    for(int i = 1; i <= X; i++)
    {
        dp[i] = n - dp[i];
        ans ^= (dp[i] * dp[i]);
    }
    cout << ans;
}