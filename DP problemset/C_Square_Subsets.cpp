#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int mask[69 + 5];
int freq[1 << 19];
int dp[2][1 << 19];
int pow2[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= 70; i++)
    {
        int x = i, b = 1;
        for (int p : primes)
        {
            int c = 0;
            while (x % p == 0)
                c++, x /= p;
            if (c & 1)
                mask[i] |= b;
            b <<= 1;
        }
    }

    int n, mx;  cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mx = max(mx, x);
        freq[x]++;
    }

    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        pow2[i] = pow2[i - 1] * 2 % mod;

    dp[0][0] = 1;
    int curr = 1, nxt = 0;
    for (int i = 0; i < mx; i++)
    {
        swap(curr, nxt);
        for (int j = 0; j < (1 << 19); j++)
        {
            if (freq[i + 1])
            {
                (dp[nxt][j ^ mask[i + 1]] += dp[curr][j] * pow2[freq[i + 1] - 1]) %= mod;
                (dp[nxt][j] += dp[curr][j] * pow2[freq[i + 1] - 1]) %= mod;
            }
            else
                dp[nxt][j] = dp[curr][j];
            dp[curr][j] = 0;
        }
    }

    int ans = (dp[nxt][0] + mod - 1) % mod;
    cout << ans;
}