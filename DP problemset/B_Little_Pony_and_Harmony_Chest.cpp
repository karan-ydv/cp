#include <bits/stdc++.h>
using namespace std;

const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int dp[105][1 << 17], fact[69];
pair<int, int> par[105][1 << 17];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 17; i++)
        for(int j = primes[i]; j < 60; j += primes[i])
            fact[j] |= 1 << i;
    
    fill_n(dp[0], 105 * (1 << 17), 1 << 30);

    int n; cin >> n;
    int a[n]; for(int &x: a)    cin >> x;
    reverse(a, a + n);

    for(int i = 0; i < n; i++)
    for(int k = 1; k < 60; k++)
    {
        int x = (~fact[k]) & ((1 << 17) - 1);
        for(int s = x; ; s = (s - 1) & x)
        {
            int &v = dp[i][s | fact[k]];
            if(dp[i - 1][s] + abs(a[i] - k) < v)
            {
                v = dp[i - 1][s] + abs(a[i] - k);
                par[i][s | fact[k]] = {s, k};
            }
            if(s == 0)  break;
        }
    }
    
    int set = 0, x;
    for(int i = 0; i < (1 << 17); i++)
        if(dp[n - 1][i] < dp[n - 1][set]) set = i;

    for(int i = n - 1; i >= 0; i--) {
        tie(set, x) = par[i][set];
        cout << x << ' ';
    }
}