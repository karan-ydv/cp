#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
int spf[N], prime[N];

void linearsieve()
{
    int c = 0;
    for (int i = 2; i < N; i++)
    {
        if (spf[i] == 0)
            spf[i] = i, prime[c++] = i;
        for (int j = 0; j < c and prime[j] <= spf[i]; j++)
        {
            int x = i * prime[j];
            if (x >= N)
                break;
            spf[x] = prime[j];
        }
    }
}

int dp[N];
void precum()
{
    linearsieve();
    for (int i = 2; i < N; i++)
        dp[i] = 1 + dp[i / spf[i]];
    partial_sum(dp, dp + N, dp);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    precum();
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a] - dp[b] << '\n';
    }
}