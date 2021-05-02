#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int B = 1e5+5;
int dp[B];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m, b;    cin >> n >> m >> b;
        vector<vector<int>> A;
        if(n > m)
        {
            swap(n, m);
            A.resize(n, vector<int>(m));
            for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++)
                cin >> A[i][j];
        }
        else
        {
            A.resize(n, vector<int>(m));
            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> A[i][j];
        }

        int ans = 0;
        for(int x = 1; x < (1 << n); x++)
        {
            vector<int> v(m);
            for(int i = 0; i < m; i++)
            for(int j = 0, b = 1; j < n; j++, b <<= 1)
                if(x & b)   v[i] += A[j][i];
            
            int y;
            if(m > 25)
            {
                fill_n(dp, b + 1, 0);
                dp[0] = 1;
                for(int i = 0; i < m; i++)
                for(int j = b; j >= v[i]; j--)
                {
                    dp[j] += dp[j - v[i]];
                    if(dp[j] >= mod)    dp[j] -= mod;
                }
                y = dp[b];
            }
            else
            {
                int c = m / 2, d = m - c;
                map<int, int> mp;
                y = 0;
                for(int z = 0; z < 1 << c; z++)
                {
                    int sum = 0;
                    for(int i = 0, j = 1; i < c; i++, j <<= 1)
                        if(z & j)  sum += v[i];
                    
                    if(sum <= b)    mp[sum]++;
                }
                for(int z = 0; z < 1 << d; z++)
                {
                    int sum = 0;
                    for(int i = 0, j = 1; i < d; i++, j <<= 1)
                        if(z & j)  sum += v[c + i];
                    
                    if(mp.count(b - sum))
                    {
                        y += mp[b - sum];
                        if(y >= mod)  y -= mod;
                    }
                }
            }
            ans += y;
            if(ans >= mod)  ans -= mod;
        }
        cout << ans << '\n';
    }
}