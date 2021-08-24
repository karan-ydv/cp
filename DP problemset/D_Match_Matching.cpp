#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e4+5;
int dp[N];
int cost[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    int a[m];   for(int &x: a)  cin >> x;
    sort(a, a + m);
    reverse(a, a + m);
    for(int x: a)   dp[cost[x]] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j : a) if(cost[j] <= i and dp[i - cost[j]])
            dp[i] = max(dp[i], dp[i - cost[j]] + 1);
    }
    string ans = "";
    while(dp[n] != 1)
    {
        bool flag = true;
        for(int x : a) if(cost[x] <= n and dp[n - cost[x]] + 1 == dp[n])
        {
            ans += char('0' + x);
            n -= cost[x];
            break;
        }
    }
    for(int x: a)   if(cost[x] == n)
    {
        ans += ('0' + x);
        break;
    }
    cout << ans;
}