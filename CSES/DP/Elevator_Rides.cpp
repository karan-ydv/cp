#include <bits/stdc++.h>
using namespace std;

pair<int, int> dp[1 << 20];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;   cin >> n >> x;
    int a[n];   for(int& w: a)  cin >> w;
    dp[0] = {1, 0};
    for(int s = 1; s < (1 << n); s++)
    {
        dp[s] = {n + 1, 0};
        for(int i = 0; i < n; i++)
        if(s & (1 << i))
        {
            auto [r, w] = dp[s ^ (1 << i)];
            if(w + a[i] <= x) {
                w += a[i];
            }
            else{
                r++;
                w = a[i];
            }
            dp[s] = min(dp[s], {r, w});
        }
    }
    cout << dp[(1 << n) - 1].first;
}