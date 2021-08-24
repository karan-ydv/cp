#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 1e5+69;
bool pref[32][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;

        for(int j = 0, x = 0; j < n; j++)
        {
            x ^= a[j];
            for(int b = 1, i = 0; b <= 1e9; b <<= 1, i++)
                pref[i][j] = ((x & b) > 0);
        }
        int ans = 0;
        for(int b = 1, i = 0; b <= 1e9; b <<= 1, i++)
        {
            int ones = 0;
            for(int j = 0; j < n; j++)
                ones += pref[i][j];
            int zeroes = n - ones;
            int prev = 0;
            for(int j = 0; j < n; j++)
            {
                int m;
                if(prev == 0)
                    m = ones;
                else
                    m = zeroes;
                (ans += b * m % mod) %= mod;
                ones -= pref[i][j];
                zeroes -= 1 - pref[i][j];
                prev = pref[i][j];
            }
        }
        cout << ans << '\n';
    }
}