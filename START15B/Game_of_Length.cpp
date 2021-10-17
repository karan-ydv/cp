#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 998244353;
const int N = 5e5 + 5;
int dp[N];

int Exp(int a, int n){
    int p = 1;
    for(; n; (a *= a) %= mod, n >>= 1)
        if(n & 1)	p = p * a % mod;
    return p;
}

inline int inv(int x) { return Exp(x, mod - 2); }

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < N; i++)
        dp[i] = (dp[i - 1] + inv(i)) % mod;
    
    int t;	cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            mp[x]++;
        }
        int k = 0;
        for(auto [x, f]: mp) {
            ++k;
            dp[k] = (dp[k - 1] + f * inv(k) % mod) % mod;
        }
        cout << dp[k] << '\n';
    }
}