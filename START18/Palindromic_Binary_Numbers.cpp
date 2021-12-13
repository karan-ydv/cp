#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool palindrome(int n) {
    string s = "";
    while(n)
    {
        if(n & 1)
            s += '1';
        else
            s += '0';
        n >>= 1;
    }
    int m = s.length();
    for(int i = 0; i < m / 2; i++)
        if(s[i] != s[m - 1 - i])
            return false;
    return true;
}

const int N = 1003;
int dp[N];
vector<int> ans[N];

void solve()
{
    for(int i = 1; i < N; i++) {
        dp[i] = 13;
        if(palindrome(i))
            ans[i].emplace_back(i), dp[i] = 1;
    }
    
    for(int i = 1; i < N; i++) if(ans[i].empty())
    for(int j = 1; j <= i / 2; j++)
    {
        if(dp[j] + dp[i - j] < dp[i])
        {
            dp[i] = dp[j] + dp[i - j];
            ans[i] = ans[j];
            ans[i].insert(ans[i].end(), ans[i - j].begin(), ans[i - j].end());
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        cout << ans[n].size() << '\n';
        for(int x: ans[n])  cout << x << ' ';
        cout << '\n';
    }
}