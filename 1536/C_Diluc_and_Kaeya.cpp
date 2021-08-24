#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        string s;   cin >> s;
        vector<int> dp(n, 1);
        int D[n], K[n];
        D[0] = s[0] == 'D';
        K[0] = s[0] == 'K';
        for(int i = 1; i < n; i++)
        {
            D[i] = D[i - 1];
            K[i] = K[i - 1];
            D[i] += s[i] == 'D';
            K[i] += s[i] == 'K';
        }
        map<pair<int, int>, int> mp;
        mp[{D[0], K[0]}] = 1;
        for(int i = 1; i < n; i++)
        {
            int g = __gcd(D[i], K[i]);
            pair<int, int> x = {D[i] / g, K[i] / g};
            dp[i] = mp[x] + 1;
            mp[x] = dp[i];
        }
        for(int x: dp)  cout << x << ' ';
        cout << '\n';
    }
}