#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 69;
int nCr[N][N];

int32_t main()
{
    nCr[1][0] = nCr[1][1] = 1;
    for(int i = 2; i < N; i++)
    {
        nCr[i][0] = 1;
        for(int j = 1; j <= i; j++)
            nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
    }
    int n, m, t; cin >> n >> m >> t;
    int ans = 0;
    for(int i = 4; i <= n; i++)
    for(int j = 1; j <= m; j++)
    if(i + j == t) ans += nCr[n][i] * nCr[m][j];
    cout << ans;
}