#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e4+5;
bitset<M> dp[N][N];

void preprocesss()
{
    for(int i = 2; i < N; i++)
        dp[1][i][i - 1] = dp[i][1][i - 1] = 1;
        
    dp[1][1] = 1;
    for(int i = 2; i < N; i++)
    for(int j = 2; j < N; j++)
    {
        dp[i][j] = (dp[i - 1][j] << j) | (dp[i][j - 1] << i);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preprocesss();
    int t;	cin >> t;
    while(t--)
    {
        int n, m, k;    cin >> n >> m >> k;
        if(dp[n][m][k])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}