// is this duplicate solution?
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &V, vector<int> &W, int X)
{
    vector<int> f(X + 1);
    for(int i = 1; i <= (int) V.size(); i++)
    {
        int v = V[i - 1], w = W[i - 1];
        for(int j = X; j >= w; j--)
            f[j] = max(f[j], f[j - w] + v);
    }
    return f[X];
}

int dp[1001];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    fill_n(dp + 2, 999, 1 << 30);
    for(int i = 1; i <= 1000; i++)
        for(int j = i; j >= 1 and i + i / j <= 1000; j--)
            dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);

    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        vector<int> w(n), v(n);
        for(int &x: w)  cin >> x, x = dp[x];
        for(int &x: v)  cin >> x;
        k = min(k, n * 12);
        cout << knapsack(v, w, k) << '\n';
    }
}