#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int X = (1 << N) - 1;
const int M = 1e6+69;
int dp[1 << N], A[M];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    
    for(int i = 0; i <= X; i++) dp[i] = -1;
    for(int i = 0; i < n; i++)  dp[A[i] ^ X] = A[i];
    
    for(int mask = X; mask >= 1; mask--)
    for(int bit = 1; bit <= X; bit <<= 1)
    if((dp[mask] != -1) and (mask & bit))
        dp[mask ^ bit] = dp[mask];

    for(int i = 0; i < n; i++)
        cout << dp[A[i]] << ' ';
}