#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

void add(int &x, int v) {
    x += v;
    if(x >= mod)
        x -= mod;
}
int dp[1000][1024];
int main()
{
    int n, m;   cin >> n >> m;
    if(n > m)   swap(n, m);
    int p = 1 << n;
    list<int> compatibles[p];
    for(int i = 0; i < p; i++)
    for(int j = 0; j < p; j++)
    {
        if()
    }
    for(int i = 0; i < p; i++)    dp[0][i] = 1;
    for(int i = 1; i < m; i++)
    for(int j = 0; j < p; j++)
    {
        for(auto k: compatibles[j])
        add(dp[i][j], dp[i - 1][k]);
    }
    cout << dp[m - 1][p - 1];
}