#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1 << 20;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    int n = s.length();

    for(int i = 0; i < n; i++) 
    for(int j = i, x = 0; j < min(n, i + 20); j++) {
        if(x & (1 << (s[j] - 'a'))) break;
        x |= 1 << (s[j] - 'a');
        dp[x] = j - i + 1;
    }

    for(int b = 1; b < N; b <<= 1)
    for(int i = 0; i < N; i++)
        if(i & b)    dp[i] = max(dp[i], dp[i ^ b]);
    
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, dp[i] + dp[i ^ (N - 1)]);
    
    cout << ans << '\n';
}