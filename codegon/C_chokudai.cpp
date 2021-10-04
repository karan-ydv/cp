#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 1e5+69;
int dp[N][10];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string k = "chokudai";
    string s;   cin >> s;
    int n = s.length();
    s = "!" + s;
    for(char i = '0'; i < '8'; i++) {
        for(int j = 1; j <= n; j++)
        if(s[j] == k[i - '0']) s[j] = i;
    }
    // cout << s;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 8; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        if(s[i] == '0') (dp[i][0] += 1) %= mod;
        if('0' < s[i] and s[i] < '8')
        (dp[i][s[i] - '0'] += dp[i - 1][s[i] - '1']) %= mod;
    }
    cout << dp[n][7];
}