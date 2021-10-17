#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 105;
const int M = 1000;
int sum[M + 5], a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= M; i++)
    for(int j = i; j; j /= 10)
        sum[i] += j % 10;
    
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        int dp[N][M + 5] = {};
        dp[0][0] = 1;
        
        vector<int> pref(M + 5, 1);
        for(int i = 1; i <= n; i++) {
            vector<int> v(M + 5);
            for(int j = 1; j <= M; j++)
            {
                if(sum[j] == a[i]) dp[i][j] = pref[j - 1];
                v[j] = (v[j - 1] + dp[i][j]) % mod;
            }
            pref.swap(v);
        }
        
        cout << pref[M] << '\n';
    }
}